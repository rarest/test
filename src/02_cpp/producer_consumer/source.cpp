//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include "thread"

struct Complex {
//    std::mutex mutex;
    std::recursive_mutex mutex;
    int i;

    Complex() : i(0) {}

    void mul(int x) {
        std::lock_guard<decltype(mutex)> lockGuard(mutex);
        i *= x;
    }

    void div(int x) {
        std::unique_lock<decltype(mutex)> uniqueLock(mutex);
        i /= x;
    }

    void both(int x, int y) {
        std::lock_guard<decltype(mutex)> lockGuard(mutex);
        mul(x);
        div(y);
    }
};

struct TimedLocking {

    std::timed_mutex mutex;

    void work() {
        std::chrono::milliseconds timeout(100);
        while (true) {
            if (mutex.try_lock_for(timeout)) {
                std::cout << std::this_thread::get_id() << ": do work with the mutex" << std::endl;
                std::chrono::milliseconds sleepDuration(250);
                std::this_thread::sleep_for(sleepDuration);
                mutex.unlock();

            } else {
                std::cout << std::this_thread::get_id() << ": do work without mutex" << std::endl;
                std::chrono::milliseconds sleepDuration(100);
                std::this_thread::sleep_for(sleepDuration);
            }
        }
    }
};

struct CallOnce {
private:
    std::once_flag onceFlag;

    void do_something() {
        std::call_once(onceFlag, []() { std::cout << "called once" << std::endl; });
        std::cout << "called each time" << std::endl;
    }

public:
    void Test() {
        std::thread t1(&CallOnce::do_something, this);
        std::thread t2(&CallOnce::do_something, this);
        std::thread t3(&CallOnce::do_something, this);
        std::thread t4(&CallOnce::do_something, this);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }
};


void testRecursiveLock() {
    Complex complex;
    complex.both(32, 23);
}


void testTimingLock() {
    TimedLocking timedLocking;
    std::thread t1(&TimedLocking::work, &timedLocking);
    std::thread t2(&TimedLocking::work, &timedLocking);
    t1.join();
    t2.join();
}

void testCallOnce() {
    CallOnce callOnce;
    callOnce.Test();
}


struct BoundedBuffer {
    std::unique_ptr<int[]> buffer;
    int capacity;
    int front;
    int rear;
    int count;
    std::mutex lock;

    std::condition_variable not_full;
    std::condition_variable not_empty;

    BoundedBuffer(int capacity_) : capacity(capacity_), front(0), rear(0), count(0) {
        buffer = std::make_unique<int[]>(capacity);
    }

    ~BoundedBuffer() {}

    void deposit(int data) {
        std::unique_lock<decltype(lock)> l(lock);
        not_full.wait(l, [this] { return count != capacity; });
        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        count++;
        l.unlock();
        not_empty.notify_one();
    }

    int fetch() {
        std::unique_lock<decltype(lock)> l(lock);
        not_empty.wait(l, [this] { return count != 0; });
        int result = buffer[front];
        front = (front + 1) % capacity;
        --count;
        l.unlock();
        not_full.notify_one();
        return result;
    }

};

void consumer(int id, BoundedBuffer &buffer) {
    for (int i = 0; i < 50; i++) {
        int value = buffer.fetch();
        std::cout << "Consumer " << id << " fetched " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void producer(int id, BoundedBuffer &buffer) {
    for (int i = 0; i < 75; ++i) {
        buffer.deposit(i);
        std::cout << "Produced " << id << " produced" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void testProduceConsume() {
    BoundedBuffer buffer(200);
    std::thread c1(consumer, 0, std::ref(buffer));
    std::thread c2(consumer, 1, std::ref(buffer));
    std::thread c3(consumer, 2, std::ref(buffer));
    std::thread p1(producer, 0, std::ref(buffer));
    std::thread p2(producer, 1, std::ref(buffer));
    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();

}


