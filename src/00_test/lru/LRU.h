//
// Created by ChenShuQuan on 2022/1/4.
//

#ifndef CPPTEST_LRU_H
#define CPPTEST_LRU_H
#include <map>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity):size(capacity) {}

    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end()) return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void set(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end())
        {
            it->second->second = value;
            return cache.splice(cache.begin(), cache, it->second);
        }
        cache.insert(cache.begin(), make_pair(key, value));
        hash[key] = cache.begin();
        if(cache.size() > size)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> cache;
    int size;
};
#endif //CPPTEST_LRU_H
