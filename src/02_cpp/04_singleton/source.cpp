//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include "common.h"
SingletonTest111 *SingletonTest111::_ptr = nullptr;

Singleton::Singleton() {
    Log("Singleton create");
}

Singleton::~Singleton() {
    Log("Singleton destroy");
}
