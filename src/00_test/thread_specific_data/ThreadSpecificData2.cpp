//
// Created by Chen Shuquan on 2020/11/25.
//

#include "ThreadSpecificData2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


pthread_key_t ThreadSpecificData2::pthread_key_;

ThreadSpecificData2::ThreadSpecificData2() {

}

ThreadSpecificData2::~ThreadSpecificData2() {

}

char *ThreadSpecificData2::str_accumulate(const char *s) {
    str_alloc_key_wrap();
    char *accu = (char *) pthread_getspecific(pthread_key_);
    if (accu == nullptr) {
        accu = (char *) malloc(1024);
        if (accu == nullptr) return nullptr;
        accu[0] = 0;
        pthread_setspecific(pthread_key_, (void *) accu);
        printf("Thread %lx: allocating buffer at %p\n", pthread_self(), accu);
    }
    strcat(accu, s);
    return accu;
}


void ThreadSpecificData2::str_alloc_key() {
    pthread_key_create(&pthread_key_, str_alloc_destroy_accu);
}

void ThreadSpecificData2::str_alloc_destroy_accu(void *accu) {
    printf("thread %lx: free buffer at %p\n", pthread_self(), accu);
    free(accu);
}

void *ThreadSpecificData2::routine(void *ptr) {
    ThreadSpecificData2 *data2 = (ThreadSpecificData2 *) ptr;
    data2->process("first");
}

void ThreadSpecificData2::run() {
    char *res;
    res = str_accumulate("Result of ");
    pthread_create(&pthread1_, nullptr, routine, this);
    pthread_create(&pthread2_, nullptr, routine2, this);
    res = str_accumulate("init thread");
    printf("Thread %lx: \"%s\"\n", pthread_self(), res);
    pthread_join(pthread1_, nullptr);
    pthread_join(pthread2_, nullptr);
    pthread_exit(0);
}

void ThreadSpecificData2::process(char *str) {
    char *res;
    res = str_accumulate("Result of ");
    if (strcmp(str, "first") == 0) {
        sleep(3);
    }
    res = str_accumulate(str);
    res = str_accumulate(" thread");
    printf("Thread %lx: \"%s\"\n", pthread_self(), res);
}

void *ThreadSpecificData2::routine2(void *ptr) {
    ThreadSpecificData2 *data2 = (ThreadSpecificData2 *) ptr;
    data2->process("second");
}

void ThreadSpecificData2::str_alloc_key_wrap() {
    static pthread_once_t str_alloc_key_once = PTHREAD_ONCE_INIT;
    pthread_once(&str_alloc_key_once, str_alloc_key);

}

