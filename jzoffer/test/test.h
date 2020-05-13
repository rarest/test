#ifndef INTERVIEW_TEST_H
#define INTERVIEW_TEST_H

#include "common.h"

BEGIN_INTERVIEW_NS

    class Foo {
    public:
        Foo() {
            cout << "Foo constructed" << endl;
        }

        ~Foo() {
            cout << "Foo destructed" << endl;
        }
    };


END_INTERVIEW_NS

#endif