//
// Created by ChenShuQuan on 2021/11/21.
//
#include "common.h"
class  A {
public:
    void hide() {
        Log("A::hide");
    }
    void hide(int val) {
        Log("A::hide val");
    }

    virtual void overrideF(){
        Log("A::overrideF");
    }
};

class B : public A {
public:
    void hide() {
        Log("B::hide");
    }
    void hide(std::string str) {
        Log("B::hide str");
    }

    void overrideF() override {
        Log("B::overrideF");
    }
};

int main() {
    A s_a;
    B s_b;
    A &p_a = s_b;
    s_a.hide();
    s_a.overrideF();
    s_b.hide();
    s_b.hide({"AAAA"});
    p_a.hide();
    p_a.overrideF();

}