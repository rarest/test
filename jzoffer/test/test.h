#ifndef INTERVIEW_TEST_H
#define INTERVIEW_TEST_H

#include "common.h"


BEGIN_INTERVIEW_NS

    class Foo {
    public:
        explicit Foo(int val) : _val(val) {
            cout << "Foo constructed " << _val << endl;
        }

        Foo() : Foo(0) {}


        ~Foo() {
            cout << "Foo destructed " << _val << endl;
        }

        void setBar(int val) {
            _val = val;
        }

        int getBar() {
            return _val;
        }

    private:
        int _val = 0;
    };

    Foo &getFoo();

    inline void printFoo() {
        Foo &foo = getFoo();
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
        foo.setBar(10);
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
    }

END_INTERVIEW_NS

#endif