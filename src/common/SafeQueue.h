/**
 * @file SafeQueue.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  线程安全的队列(通过封装STL Queue实现)
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <mutex>
#include <queue>
template <typename T>
class SafeQueue {
private:
  std::queue<T> m_queue;
  std::mutex m_mutex;
public:
  SafeQueue() {

  }

  SafeQueue(SafeQueue& other) {
    //TODO:
  }

  ~SafeQueue() {

  }

  bool empty() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.empty();
  }
  
  int size() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.size();
  }

  void enqueue(T& t) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(t);
  }
  
  bool dequeue(T& t) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_queue.empty()) {
      return false;
    }
    t = std::move(m_queue.front());
    
    m_queue.pop();
    return true;
  }
};