//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "../forwardStatment/source.h"
#include <memory>

struct Foo { // object to manage
    Foo() { std::cout << "Foo ctor\n"; }

    Foo(const Foo &) { std::cout << "Foo copy ctor\n"; }

    Foo(Foo &&) { std::cout << "Foo move ctor\n"; }

    ~Foo() { std::cout << "~Foo dtor\n"; }
};

struct D { // deleter
    D() {};

    D(const D &) { std::cout << "D copy ctor\n"; }

    D(D &) { std::cout << "D non-const copy ctor\n"; }

    D(D &&) { std::cout << "D move ctor \n"; }

    void operator()(Foo *p) const {
        std::cout << "D is deleting a Foo\n";
        delete p;
    };
};

Foo &&getFoo() {
    return Foo();
}

Foo &&getFoo1() {
    return std::move(Foo());
}

Foo getFoo2() {
    return std::move(Foo());
}

Foo getFoo3() {
    return Foo();
}

int main() {

    Foo foo = getFoo();
    Foo foo1 = getFoo1();
    Foo foo2 = getFoo2();
    Foo&& foo3 = getFoo3();
    Foo  foo4 = foo3;
    {
        Log("临时变量释放");
        getFoo3();
        Foo foo5 = getFoo3();
    }

    Log("end");
    return 0;
}