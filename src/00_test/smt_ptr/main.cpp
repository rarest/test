//
// Created by ChenShuQuan on 2021/11/21.
//
#include "common.h"
#include <memory>
#include <string>
#include "smart_ptr.h"

int main() {
int *p1 = new int;
int *p2 = new int();


//    std::unique_ptr <std::string> p1(new std::string("auto ptr!"));
//    std::unique_ptr <std::string> p2 = std::move(p1);
//    Log("p1: %s p2: %s", p1.get() ? p1->c_str() : "", p2->c_str());
//    std::unique_ptr <std::string> p3(new std::string("unique ptr!"));
//    std::unique_ptr <std::string> p4 = std::move(p3);
//    Log("p3: %s p4: %s", p3.get() ? p3->c_str() : "", p4->c_str());
//    std::unique_ptr <std::string> p5 = std::make_unique<std::string>("make_unique string!");
//    std::shared_ptr <std::string> p6(std::make_unique<std::string>("make_unique string!"));
////    std::shared_ptr<std::string> p8(p5); compile error
//    std::shared_ptr <std::string> p7(p6);
//    Log("p6 useCount: %ld", p6.use_count());
//    p5.release();
//    Log("p6 useCount: %ld %s", p6.use_count(), p6->c_str());


}