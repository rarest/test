#include "test.h"

BEGIN_INTERVIEW_NS
    static Foo foo;
    Foo &getFoo() {
        return foo;
    }

    void externFunction() {
        printf("test extern function\n");
    }

END_INTERVIEW_NS