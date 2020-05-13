#include "test.h"

BEGIN_INTERVIEW_NS
    extern void externFunction();
END_INTERVIEW_NS

USE_INTERVIEW_NS

int main() {
    Foo &foo = getFoo();
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    foo.setBar(5);
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    printFoo();

    externFunction();
}