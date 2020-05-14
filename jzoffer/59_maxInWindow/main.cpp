//
// Created by Chen Shuquan on 2020/5/13.
//

#include "maxInWindow.h"
#include "maxQueue.h"

#include <random>

vector<int> randomArray(int len, int seed) {
    default_random_engine e;
    e.seed(5);
    uniform_int_distribution<uint8_t> u(0, 100);
    vector<int> data, ret;
    cout << "input: ";
    for (int i = 0; i < 10; i++) {
        int val = u(e);
        data.push_back(val);
        cout << val << " ";
    }
    cout << endl;
    return data;
}

void testMaxInWindow() {
    vector<int> data, ret;
    int len = 10, seed = 5;
    data = randomArray(len, 5);
    for (int i = 1; i < len; i++) {
        ret.clear();
        ret = maxInWindow(data, i);
        cout << "wSize: " << i << " output: ";
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
}

void testMaxQueue() {
    int len = 10, seed = 5;
    vector<int> data, ret;
    data = randomArray(len, seed);
    MaxQueue<int> maxQueue;

    cout << "output: " << endl;
    for (int i = 0; i < data.size(); i++) {
        maxQueue.push_back(data[i]);
        int max = maxQueue.max();
        cout << "push: " << data[i] << " max: " << max << endl;
    }

    for (int i = 0; i < data.size(); i++) {
        try {
            int val = maxQueue.front();
            maxQueue.pop_front();
            int max = maxQueue.max();
            cout << "pop: " << val << " max: " << max << endl;

        } catch (std::runtime_error e) {
            cout << "exception: " << e.what() << endl;
        }
    }


}

int main() {
    testMaxInWindow();
    testMaxQueue();
}

