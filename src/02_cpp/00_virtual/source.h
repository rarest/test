//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"

class Empty {

};

class OneFunction {
private:
    void f() {}
};

class OneMemberChar {

private:
    char a;
};

#pragma  pack(push, 4)

class OneMemberInt {
public:
    OneMemberInt() {}

    virtual ~OneMemberInt() {}

private:
    int a;
};

#pragma pack(pop)


class Base {
public:
    void d() { printf("Base::d()\n"); }

public:
    virtual void f() { printf("Base::f()\n"); }

private:
    virtual void g() { printf("Base::g()\n"); }

    virtual void h() { printf("Base::h()\n"); }
};

class Derived : public Base {
public:
    void d() { printf("Derived::d()\n"); }

    void f(int a) { printf("Derived::f() %d,\n", a); }

    virtual void f1() { printf("Derived::f1()\n"); }

    virtual void g1() { printf("Derived::g1()\n"); }

    virtual void h1() { printf("Derived::h1()\n"); }


};


class Base1 {
public:
    virtual void f() { printf("Base1::f()\n"); }


    virtual void g() { printf("Base1::g()\n"); }

private:
    virtual void h() { printf("Base1::h()\n"); }
};

class Base2 {
public:
    virtual void f() { printf("Base2::f()\n"); }


    virtual void g() { printf("Base2::g()\n"); }

private:
    virtual void h() { printf("Base2::h()\n"); }
};

class Base3 {
public:
    virtual void f() { printf("Base3::f()\n"); }


    virtual void g() { printf("Base3::g()\n"); }

private:
    virtual void h() { printf("Base3::h()\n"); }
};

class MultiDerived : public Base1, Base2, Base3 {
public:
    virtual void f() { cout << "MultiDerived::f" << endl; }

    virtual void g1() { cout << "MultiDerived::g1" << endl; }
};


#endif //INTERVIEW_SOURCE_H
