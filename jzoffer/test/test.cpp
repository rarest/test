#include "test.h"

BEGIN_INTERVIEW_NS
    static Foo foo;
    Foo &getFoo() {
        return foo;
    }

    void printFoo() {
        Foo &foo = getFoo();
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
        foo.setBar(10);
        printf("in printFoo foo(%p) is %d\n", &foo, foo.getBar());
        add();
    }


END_INTERVIEW_NS