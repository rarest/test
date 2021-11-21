//
// Created by ChenShuQuan on 2021/11/14.
//
#include "common.h"
#include "CMyString.h"
#include "RValue.h"
#include <vector>

int test1() {
    std::vector<CMyString> strArray;
    strArray.reserve(1000);
    for (int i = 0; i < 1000; i++) {
        CMyString str = CMyString();
        strArray.push_back(str);
    }
    Log("ctor %d cctor %d mctor %d ca %d ma %d", CMyString::ctorCount, CMyString::cctorCount, CMyString::mctorCount,
        CMyString::casignCount, CMyString::masignCount);
    CMyString::reset();
    strArray.clear();
    strArray.reserve(1000);
    for (int i = 0; i < 1000; i++) {
        CMyString str = CMyString();
        strArray.push_back(std::move(str));
    }
    Log("ctor %d cctor %d mctor %d ca %d ma %d", CMyString::ctorCount, CMyString::cctorCount, CMyString::mctorCount,
        CMyString::casignCount, CMyString::masignCount);
    CMyString::reset();
    strArray.clear();
    strArray.reserve(1000);
    for (int i = 0; i < 1000; i++) {
        strArray.emplace_back(CMyString());
    }
    Log("ctor %d cctor %d mctor %d ca %d ma %d", CMyString::ctorCount, CMyString::cctorCount, CMyString::mctorCount,
        CMyString::casignCount, CMyString::masignCount);
    return 0;
}

int test2() {
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][27]: ctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][27]: ctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][44]: cctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][54]: mctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/main.cpp][test2][43]: str1.getData() (null)
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][27]: ctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][operator=][60]: casign
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][CMyString][27]: ctor
//    [/Users/chenshuquan/Projects/test/src/02_cpp/07_RValue/CMyString.cpp][operator=][78]: masign
    CMyString str1("hello"); //调用构造函数
    CMyString str2("world"); //调用构造函数
    CMyString str3(str1); //调用拷贝构造函数
    CMyString str4(std::move(str1)); // 调用移动构造函数、
    Log("str1.getData() %s", str1.getData());
    CMyString str5;
    str5 = str2; //调用拷贝赋值函数
    CMyString str6;
    str6 = std::move(str2); // str2的内容也失效了，不要再使用
    Log("str5.getData() %s str6.getData() %s", str5.getData(), str6.getData());
}

void test3() {
    int x = 1;
    f(1); // 参数是右值 T推导成了int, 所以是int&& param, 右值引用
    f(x); // 参数是左值 T推导成了int&, 所以是int&&& param, 折叠成 int&,左值引用
    int &&a = 2;
    f(a); //虽然a是右值引用，但它还是一个左值， T推导成了int&
    std::string str = "hello";
    f(str); //参数是左值 T推导成了string&
    f(std::string("hello")); //参数是右值， T推导成了string
    f(std::move(str));//参数是右值， T推导成了string
}

void test4() {
    int a = 0;
    process(a); //a被视为左值 process(int&):0
    process(1); //1被视为右值 process(int&&):1
    process(move(a)); //强制将a由左值改为右值 process(int&&):0
    myforward(2);  //右值经过forward函数转交给process函数，却称为了一个左值，
    //原因是该右值有了名字  所以是 process(int&):2
    myforward(move(a));  // 同上，在转发的时候右值变成了左值  process(int&):0
//    myforward(a); // 错误用法，右值引用不接受左值
}

void test5() {
    int a = 0;
    int b = 0;
    const int c = 0;
    const int d = 0;

    notPerfectForward(a); // lvalue ref
    notPerfectForward(move(b)); // lvalue ref
    notPerfectForward(c); // const lvalue ref
    notPerfectForward(move(d)); // const lvalue ref

    cout << endl;
    perfectForward(a); // lvalue ref
    perfectForward(move(b)); // rvalue ref
    perfectForward(c); // const lvalue ref
    perfectForward(move(d)); // const rvalue ref
}

CMyString getCMyString() {
    return CMyString();
}

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A {
    A() {
        cout << "construct: " << ++g_constructCount << endl;
    }

    A(const A &a) {
        cout << "copy construct: " << ++g_copyConstructCount << endl;
    }

    ~A() {
        cout << "destruct: " << ++g_destructCount << endl;
    }
};

A GetA() {
    return A();
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    A a = GetA();
    A&& aa = GetA();
    return 0;
}
