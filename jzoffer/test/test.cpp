#include "test.h"

BEGIN_INTERVIEW_NS

    void printFoo() {
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
        foo.setBar(10);
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
    }

END_INTERVIEW_NS