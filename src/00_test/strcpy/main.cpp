//
// Created by ChenShuQuan on 2021/11/24.
//

#include "common.h"

char *strcpy(char *dst, const char *src) {
    char *ret = dst;
    assert(dst);
    assert(src);
    while (*src != '\0') {
        *(dst++) = *(src++);
    }
    *dst = '\0';
    return ret;
}

char *strcat(char *dst, const char *src) {
    char *ret = dst;
    assert(dst);
    assert(src);
    while (*dst != '\0')
        dst++;
    while (*src != '\0')
        *(dst++) = *(src++);
    *dst = '\0';
    return ret;
}
// 1 s1>s2
// 0 s1=s2
// -1 s1<s2

int strcmp(const char *s1, const char *s2) {
    assert(s1);
    assert(s2);
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 > *s2) {
            return 1;
        } else if (*s1 < *s2) {
            return -1;
        } else {
            ++s1;
            ++s2;
        }
    }
    if (*s1 > *s2)
        return 1;
    else if (*s1 < *s2)
        return -1;
    else
        return 0;
}

char *strstr(char *str, char *sub) {
    assert(str);
    assert(sub);
    char *s = str;
    while (*s != '\0') {
        char *s1 = s;
        char *s2 = sub;
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
            ++s1;
            ++s2;
        }
        if (*s2 == '\0')
            return s;
        if (*s1 == '\0')
            return nullptr;
        ++s;
    }
    return nullptr;
}

__attribute((constructor)) void before() {
    Log("before main1");
}

int test() {
    Log("before main2");
    return 0;
}

static int a = test();
int b = test();
auto func = []() {
    Log("before main3");
    return 1;
};
int c = func();

int main() {
    Log("main");
    char dst[32];
    const char *src = "hello world";
    char *ret = strcpy(dst, src);
    Log("cpy ret: %s", ret);

    ret = strcat(dst, src);
    Log("cat ret: %s", ret);

    ret = strstr(dst + 1, src);
    Log("strstr ret: %s", ret);
}