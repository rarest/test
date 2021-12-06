//
// Created by Chen Shuquan on 2021/12/6.
//
#include <memory>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <chrono>


class RingBuffer {
private:
    std::unique_ptr<int[]> buffer_;
    int capacity_;
    int front_;
    int rear_;
    int count_;
    std::mutex mutex_;
    std::condition_variable not_full_;
    std::condition_variable not_empty_;
public:
    RingBuffer(int cap) : capacity_(cap), front_(0), rear_(0), count_(0) {
        if (capacity_ <= 0) {
            capacity_ = 100;
        }
        buffer_ = std::make_unique<int[]>(capacity_);
    }

    ~RingBuffer() {}

    void pushData(int data) {
        std::unique_lock<std::mutex> lock(mutex_);
        not_full_.wait(lock, [this] { return count_ != capacity_; });
        buffer_[rear_] = data;
        rear_ = (rear_ + 1) % capacity_;
        ++count_;
        lock.unlock();
        not_empty_.notify_one();
    }

    int getData() {
        std::unique_lock<std::mutex> lock(mutex_);
        not_empty_.wait(lock, [this] { return count_ != 0; });
        int data = buffer_[front_];
        front_ = (front_ + 1) % capacity_;
        --count_;
        lock.unlock();
        not_full_.notify_one();
        return data;
    }
};

void consumer(int id, int nums, RingBuffer &boundedBuffer) {
    for (int i = 0; i < nums; ++i) {
        int val = boundedBuffer.getData();
        std::cout << "consumer id:" << id << " times: " << i << " consume val: " << val << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void producer(int id, int nums, RingBuffer &boundedBuffer) {
    for (int i = 0; i < nums; ++i) {
        boundedBuffer.pushData(i);
        std::cout << "producer id:" << id << " produce val: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}


int main() {
    RingBuffer buffer(100);
    std::thread c1(consumer, 0, 50, std::ref(buffer));
    std::thread c2(consumer, 1, 50, std::ref(buffer));
    std::thread c3(consumer, 2, 50, std::ref(buffer));
    std::thread p1(producer, 0, 75, std::ref(buffer));
    std::thread p2(producer, 1, 75, std::ref(buffer));
    c1.join();c2.join();c3.join();p1.join();p2.join();
}


