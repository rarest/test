//
// Created by Chen Shuquan on 2020/6/2.
//
#include "LFU.h"
using namespace std;

LFUCache::LFUCache(int _capacity) {
    minfreq = 0;
    capacity = _capacity;
    key_table.clear();
    freq_table.clear();
}

int LFUCache::get(int key) {
    if (capacity == 0) return -1;
    auto it = key_table.find(key);
    if (it == key_table.end()) return -1;
    list<Node>::iterator node = it->second;
    int val = node->val, freq = node->freq;
    freq_table[freq].erase(node);
    // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
    if (freq_table[freq].size() == 0) {
        freq_table.erase(freq);
        if (minfreq == freq) minfreq += 1;
    }
    // 插入到 freq + 1 中
    freq_table[freq + 1].push_front(Node(key, val, freq + 1));
    key_table[key] = freq_table[freq + 1].begin();
    return val;
}

void LFUCache::put(int key, int value) {
    if (capacity == 0) return;
    auto it = key_table.find(key);
    if (it == key_table.end()) {
        // 缓存已满，需要进行删除操作
        if (key_table.size() == capacity) {
            // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
            auto it2 = freq_table[minfreq].back();
            key_table.erase(it2.key);
            freq_table[minfreq].pop_back();
            if (freq_table[minfreq].size() == 0) {
                freq_table.erase(minfreq);
            }
        }
        freq_table[1].push_front(Node(key, value, 1));
        key_table[key] = freq_table[1].begin();
        minfreq = 1;
    } else {
        // 与 get 操作基本一致，除了需要更新缓存的值
        list<Node>::iterator node = it->second;
        int freq = node->freq;
        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        freq_table[freq + 1].push_front(Node(key, value, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
    }
}
