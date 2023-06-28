#pragma once

#include <memory>
#include <atomic>
template<typename T>
class Buffer
{
public:
    Buffer() : back(new T), middle(new T), front(new T), queued(false) {}

    void put(const T &data)
    {
        *back = data;

        // Swap middle buffer with back buffer
        std::shared_ptr<T> previous = std::atomic_exchange(&middle, back);
        std::atomic_store(&back, previous);

        queued = true;
    }

    bool get(T &data)
    {
        if (!std::atomic_exchange(&queued, false))
        {
            return false;
        }
        std::shared_ptr<T> previous = std::atomic_exchange(&middle, front);
        std::atomic_store(&front, previous);

        data = *front;

        return true;
    }

private:
    std::shared_ptr<T> back, middle, front;
    std::atomic<bool> queued;
};
