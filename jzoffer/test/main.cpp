#include "test.h"

BEGIN_INTERVIEW_NS
    extern void externFunction();
END_INTERVIEW_NS

USE_INTERVIEW_NS

#include <cerrno>

void testIO() {
    int intVal = 10;
    float fVal = 3.1415;
    double  dVal = 1323300240.432423232;
    printf("input %d, %f %f\n", intVal, fVal, dVal);
    FILE *f = fopen("./file.bin", "w+");
    fwrite(&intVal, sizeof(int), 1, f);
    fwrite(&fVal, sizeof(float), 1, f);
    fwrite(&dVal, sizeof(double),1, f);
    fclose(f);
    FILE *rf = fopen("./file1.bin", "r+");
    if(!rf) {
        printf("fopen error: %s\n", strerror(errno));
    }
    int iv = 0;
    float fv = 0.0;
    double dv = 0.0;
    fread(&iv, sizeof(int),1, rf);
    fread(&fv, sizeof(float),1, rf);
    fread(&dv, sizeof(double ),1, rf);
    fclose(rf);
    printf("output %d, %f %f\n", iv, fv, dv);
}

int main() {
    Foo &foo = getFoo();
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    foo.setBar(5);
    printf("in main foo(%p) is %d\n", &foo, foo.getBar());
    printFoo();

    externFunction();


    testIO();
}