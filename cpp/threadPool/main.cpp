//
// Created by Chen Shuquan on 2020/6/4.
//

#include "ThreadPool3.h"
#include <common.h>

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


int main() {

    testThreadPool31();
    testThreadPool32();
    LOG(error,"test error");

    return 0;
}


