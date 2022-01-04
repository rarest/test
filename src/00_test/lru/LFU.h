//
// Created by Chen Shuquan on 2021/11/19.
//

#ifndef CPP_TEST_LRU_H
#define CPP_TEST_LRU_H

#include <list>
#include <unordered_map>

struct Node {
    int key, val, freq;

    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
private:
    int minfreq, capacity;
    std::unordered_map<int, std::list<Node>::iterator> key_table;
    std::unordered_map<int, std::list<Node>> freq_table;
public:
    LFUCache(int _capacity);

    int get(int key);

    void put(int key, int value);
};

#endif //CPP_TEST_LRU_H
