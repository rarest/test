//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

class parent {
protected:
    parent(int i) {};
    virtual ~parent(){}
};

class child : public parent {
public:
    child() : parent(1),
              i(1) {};
    ~child(){}
private:
    int i;
};

int main() {
    parent *p1 = new child();

    SingletonTest *p = new SingletonTest;
    SingletonTest::Instance()->test();
    SingletonTest::Instance()->test();

    SingletonTest111::Instance().test();
    SingletonSample::Instance().test();
    Singleton *singleton = Singleton::instance();
    return 0;
}