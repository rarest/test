//
// Created by Chen Shuquan on 2020/6/4.
//

#include "ThreadPool3.h"
#include "threadPool1.h"
#include "threadpool.h"

using namespace interview;

void testThreadPool31() {
    {
        ThreadPool3 threadPool3(3);
        getchar();
    }
    getchar();

}

std::mutex g_mutex;

void priorityFunc() {
    for (int i = 1; i < 4; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(g_mutex);
        std::cout << "priorityFunc() [" << i << "at thread [ " << get_tid() << "] output" << endl;// << std::endl;
    }

}

void testFunc() {
    // loop to print character after a random period of time
    for (int i = 1; i < 4; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(g_mutex);
        cout << "testFunc() [" << i << "] at thread [ " << get_tid() << "] output" << endl;// << std::endl;
    }

}


void testThreadPool32() {
    ThreadPool3 threadPool(3);

    for (int i = 0; i < 5; i++)
        threadPool.addTask(testFunc);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    threadPool.addTaskPair(ThreadPool3::TaskPair(ThreadPool3::kPriority_level0, priorityFunc));
    getchar();
}


void testTreadPool() {
    ThreadPool pool(4);
    std::vector< std::future<int> > results;

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
                pool.enqueue([i] {
                    std::cout << "hello " << i << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "world " << i << std::endl;
                    return i*i;
                })
        );
    }

    for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;

}


void fun(int i) {
    printf("log %d", i);
}

void fun(int *i) {
    printf("log point %p", i);
}

int main() {

    int *pi = NULL;
    char *pc = NULL;
    NULL;
//    fun(NULL);
    testTreadPool();

//    int a = 0x12345678;
//    char *p = reinterpret_cast<char *>(&a);
//    printf("%x %x %x %x %x\n", a, p[0], p[1], p[2], p[3]);

//    testThreadPool31();
//    testThreadPool32();
//    LOG(error, "test error");

    return 0;
}


