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
public:
    A() {
        Log("A ctor");
    }

    ~A() {
        Log("A dtor");
    }
};

class B {
public:
    B() {
        Log("B ctor");
    }

    ~B() {
        Log("B dtor");
    }

    virtual void func() {}
};

class C {
public:
    C() {
        Log("C ctor");
    }

    ~C() {
        Log("C dtor");
    }

    static int a;
};

int C::a = 0;

class D {
public:
    D() {
        Log("D ctor");
    }

    ~D() {
        Log("D dtor");
    }

    int a;
};

class E {
public:
    E() : c(new C()), d(new D()) {
        Log("E ctor");
    }

    ~E() {
        Log("E dtor");
        delete c;
        delete d;
        c = nullptr;
        d = nullptr;
    }

    static int m;
    int n;
private:
    D *d;
    C *c;
    B b;
    A a;

};

int main() {
    E e;
    Log("sizeof(A) %lu sizeof(B) %lu sizeof(C) %lu sizeof(D) %lu sizeof(E) %lu", sizeof(A), sizeof(B), sizeof(C), sizeof(D),
        sizeof(e));

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