//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

int main() {

    std::auto_ptr<std::string> p1(new std::string("auto ptr!"));
    std::auto_ptr<std::string> p2 = p1;
    Log("p1 %s p2%s", p1.get() ? p1->c_str() : "", p2->c_str());
    std::unique_ptr<std::string> p3(new std::string("unique ptr!"));
    std::unique_ptr<std::string> p4 = std::move(p3);
    Log("p3 %s p4 %s", p3.get() ? p3->c_str() : "", p4->c_str());
    std::unique_ptr<std::string> p5 = std::make_unique<std::string>("make_unique string!");
    return 0;
}