//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include <memory>

struct Foo { // object to manage
    Foo() {
        Log("Foo ctor: %p", this);
    }

    Foo(const Foo &foo) {
        Log("Foo copy ctor: %p <- %p", this, &foo);
    }

    Foo(Foo && foo) {
        Log("Foo move ctor: %p <- %p", this, &foo);
    }

    ~ Foo() {
        Log("Foo dtor: %p", this);
    }

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

    //Foo ctor
    //~Foo dtor
    //Foo move ctor
    Log("Foo foo = getFoo();");
    Foo foo = getFoo();
    //Foo ctor
    //~Foo dtor
    //Foo move ctor
    Log("\nFoo foo1 = getFoo1();");
    Foo foo1 = getFoo1();
    //Foo ctor
    //Foo move ctor
    //~Foo dtor
    //Foo move ctor
    //~Foo dtor
    Log("\nFoo foo2 = getFoo2();");
    Foo foo2 = getFoo2();

    //Foo ctor
    //Foo move ctor
    //~Foo dtor
    Log("\nFoo&& foo3 = getFoo3();");
    Foo &&foo3 = getFoo3();

    //Foo ctor
    //Foo move ctor
    //~Foo dtor
    //Foo copy ctor
    Log("\nFoo  foo4 = foo3;");
    Foo foo4 = foo3;
    {
        Log("\n临时变量释放");
        //Foo ctor
        //Foo move ctor
        //~Foo dtor
        //~Foo dtor
        Log("getFoo3();");
        getFoo3();
        //Foo ctor
        //Foo move ctor
        //~Foo dtor
        //Foo move ctor
        //~Foo dtor
        Log("\nFoo foo5 = getFoo3();");
        Foo foo5 = getFoo3();
    }

    Log("\nend");
    return 0;
}