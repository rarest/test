//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"
#include <typeinfo>

//https://blog.csdn.net/haoel/article/details/1948051/

typedef void(*FUN)(void);


void printVTable(intptr_t *vtb, int n) {
    if (!*vtb) return;

    printf("vtb: %p\n", vtb);
    for (int i = 0; i < n; i++) {
        printf("func: %d: %#x->", i, vtb[i]);
        FUN f = (FUN) vtb[i];
        f();
    }
    printf("\n");
}

int main() {
    Base b;
    EmptyChild ec;
    EmptyChildVirturl ecv;
    printf("size of ec %lu ecv %lu\n",sizeof(ec),sizeof(ecv));

    intptr_t *vtb = *(intptr_t **)&b;
    printVTable(vtb, 3);
#if 1
    intptr_t * vtb_1 = *((intptr_t **)&b + 0);
    for(int i = 0; i < 3; ++i) {
        FUN fun1 = (FUN) *(vtb_1 + i);
        fun1();
    }
#endif

    Derived d;
    vtb = (intptr_t *) *(intptr_t *) (&d);
    printVTable(vtb, 6);

    MultiDerived multiDerived;

    printf("size of b %lu d %lu multiDerived %lu\n",sizeof(b),sizeof(d),sizeof(multiDerived));
#if 1
    intptr_t * vtb_3 =  *((intptr_t**) &multiDerived +1);
    FUN fun3 = (FUN) *(vtb_3 + 2);
    fun3();
    intptr_t ** vtb_2 = (intptr_t **) &multiDerived;
    for(int i = 0; i < 4; ++i) {
        FUN fun1 = (FUN) *(*(vtb_2+1) + i);
        fun1();
    }
#endif
    intptr_t **ppvtb = (intptr_t **) &multiDerived;
    FUN func = nullptr;
    func = (FUN) ppvtb[0][0];
    func();
    func = (FUN) ppvtb[0][1];
    func();
    func = (FUN) ppvtb[0][2];
    func();
    func = (FUN) ppvtb[0][3];
    func();
    func = (FUN) ppvtb[0][4];
    cout << func << endl;
    printf("%#X\n", ppvtb[0][4]);

    func = (FUN) ppvtb[1][0];
    func();
    func = (FUN) ppvtb[1][1];
    func();
    func = (FUN) ppvtb[1][2];
    func();
    func = (FUN) ppvtb[1][3];
    cout << func << endl;
    printf("%#X\n", ppvtb[1][3]);

    func = (FUN) ppvtb[2][0];
    func();
    func = (FUN) ppvtb[2][1];
    func();
    func = (FUN) ppvtb[2][2];
    func();
    func = (FUN) ppvtb[2][3];
    cout << func << endl;
    printf("%#X\n", ppvtb[2][3]);


    Base *base = new Derived();
    base->f();
    base->Base::f();
    size_t point_size = sizeof(base);
    size_t emptyClass_size = sizeof(Empty);
    size_t oneFunClass_size = sizeof(OneFunction);
    size_t int_size = sizeof(int);
    size_t oneMemberChar_size = sizeof(OneMemberChar);
    size_t oneMemberInt_size = sizeof(OneMemberInt);
    size_t virtualClass_size = sizeof(Base);
    printf("point_size %d empty_size %d oneFunClass_size %d \nint_size %d oneMember_size %d \noneMemberInt_size %d virtualClass_size %d",
           point_size, emptyClass_size, oneFunClass_size, int_size, oneMemberChar_size, oneMemberInt_size,
           virtualClass_size);
    return 0;
}