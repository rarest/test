//
// Created by ChenShuQuan on 2021/11/23.
//
#include "common.h"

class Foo {
public:
//    Foo() : Foo(1) {
//        Log("Foo()", val_);
//    }

    Foo() {
        new(this)Foo(1);
        Log("Foo()", val_);
    }

    Foo(int val) : val_(val) {
        Log("Foo(int)", val_);
    }

    virtual ~Foo() {
        Log("~Foo()", val_);
    }

public:
    virtual void setVal(int val) {
        val_ = val;
    }

    virtual int getVal() const {
        Log("val: %d", val_);
        return val_;
    }

private:
    virtual void setValVirtual(int val) {
        setVal(val);
    }

protected:
    int val_;
};

class Bar : public Foo {
public:
    Bar(int val) : Foo(val) {}

public:
    void setVal(int val) override {
        Foo::setVal(val);
    }

    int getVal() const override {
        return Foo::getVal();
    }

    void setValVirtual(int val) override {
        setVal(val);
    }
};

int test(const Foo *foo) {
    return foo->getVal();
}

class A {
};

class B {
    virtual void func() {}
};

class C {
    static int a;
};

int C::a = 0;

class D {
    int a;
};

class E {
    static int a;
    int b;
};

int main() {
    Log("sizeof(A) %lu sizeof(B) %lu sizeof(C) %lu sizeof(D) %lu", sizeof(A), sizeof(B), sizeof(C), sizeof(D));

    Foo foo5;
    foo5.getVal();
    Foo foo(1), foo1(1);
    Foo *const foo2 = &foo;
    const Foo *foo3 = &foo;
    *foo2 = foo1;
    foo3 = &foo1;
    foo.setVal(1);
    Bar bar(2);
    bar.setValVirtual(1);
    Foo *foo4 = &bar;
    foo4->setVal(11);
    int i = 10, b = 5;
    const int *i1 = &i;
    int *const i2 = &i;
    i1 = &b;
    *i2 = b;

}