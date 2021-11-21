//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"
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

    std::auto_ptr<std::string> p1(new std::string("auto ptr!"));
    std::auto_ptr<std::string> p2 = p1;
    Log("p1: %s p2: %s", p1.get() ? p1->c_str() : "", p2->c_str());
    std::unique_ptr<std::string> p3(new std::string("unique ptr!"));
    std::unique_ptr<std::string> p4 = std::move(p3);
    Log("p3: %s p4: %s", p3.get() ? p3->c_str() : "", p4->c_str());
    std::unique_ptr<std::string> p5 = std::make_unique<std::string>("make_unique string!");
    std::shared_ptr<std::string> p6(std::make_unique<std::string>("make_unique string!"));
//    std::shared_ptr<std::string> p8(p5); compile error
    std::shared_ptr<std::string> p7(p6);


    Log("p6 useCount: %ld", p6.use_count());
    p5.release();
    Log("p6 useCount: %ld %s", p6.use_count(), p6->c_str());

//    Foo foo = getFoo();
//    Foo foo1 = getFoo1();
//    Foo foo2 = getFoo2();
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