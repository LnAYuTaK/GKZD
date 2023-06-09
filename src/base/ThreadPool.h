#pragma once
/**
 * @file ThreadPool.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  线程池
 * @version 0.1
 * @date 2023-06-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
#include "SafeQueue.h"

static const int ThreadDealutNum = 5;

class ThreadPool {
  DISALLOW_COPY_AND_ASSIGN(ThreadPool);

 private:
  class ThreadWorker {
   private:
    int m_id;
    ThreadPool *m_pool = nullptr;

   public:
    ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id) {}
    void operator()() {
      std::function<void()> func;
      bool dequeued;
      while (!m_pool->m_shutdown) {
        {
          std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
          if (m_pool->m_queue.empty()) {
            m_pool->m_conditional_lock.wait(lock);
          }
          dequeued = m_pool->m_queue.dequeue(func);
        }
        if (dequeued) {
          func();
        }
      }
    }
  };

  bool m_shutdown;
  SafeQueue<std::function<void()>> m_queue;
  std::vector<std::thread> m_threads;
  std::mutex m_conditional_mutex;
  std::condition_variable m_conditional_lock;

 public:
  static ThreadPool *Instance(bool create_if_needed = true) {
    static ThreadPool *instance = nullptr;
    if (!instance && create_if_needed) {
      static std::once_flag flag;
      std::call_once(flag, [&] {
        instance = new (std::nothrow) ThreadPool(ThreadDealutNum);
      });
    }
    return instance;
  }

  //结束关闭所有线程
  void shutdown() {
    m_shutdown = true;
    m_conditional_lock.notify_all();

    for (size_t i = 0; i < m_threads.size(); ++i) {
      if (m_threads[i].joinable()) {
        m_threads[i].join();
      }
    }
  }
  //提交一个线程任务异步执行
  template <typename F, typename... Args>
  auto submit(F &&f, Args &&... args) -> std::future<decltype(f(args...))> {
    std::function<decltype(f(args...))()> func =
        std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    auto task_ptr =
        std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
    std::function<void()> wrapper_func = [task_ptr]() { (*task_ptr)(); };

    m_queue.enqueue(wrapper_func);

    m_conditional_lock.notify_one();

    return task_ptr->get_future();
  }

 private:
  ThreadPool(const int n_threads)
      : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {
    for (size_t i = 0; i < m_threads.size(); ++i) {
      m_threads[i] = std::thread(ThreadWorker(this, i));
    }
  }
};
