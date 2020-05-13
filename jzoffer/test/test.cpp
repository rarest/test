#include "test.h"

BEGIN_INTERVIEW_NS
    static Foo foo;
    Foo &getFoo() {
        return foo;
    }




END_INTERVIEW_NS