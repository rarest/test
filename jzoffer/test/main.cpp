#include "test.h"

USE_INTERVIEW_NS

int main() {
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    foo.setBar(5);
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    printFoo();
}