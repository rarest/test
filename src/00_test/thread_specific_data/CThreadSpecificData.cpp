//
// Created by Chen Shuquan on 2020/11/25.
//

#include "CThreadSpecificData.h"
#include <string>

CThreadSpecificData::CThreadSpecificData() {
    pthread_key_create(&pthread_key_, NULL);
}

CThreadSpecificData::~CThreadSpecificData() {

}

void CThreadSpecificData::thread1() {
    printf("thread %lu is running", pthread_self());
    pthread_create(&pthread2_, nullptr, rutin2, (void *) this);
//    int key_value = 1;
//    pthread_setspecific(pthread_key_, reinterpret_cast<void *>(static_cast<intptr_t>(key_value)));
//    printf("thread: %lu return %d\n", pthread_self(),
//           static_cast<int>(reinterpret_cast<intptr_t>(pthread_getspecific(pthread_key_))));

    std::string str_value = "thread1 key value";
    pthread_setspecific(pthread_key_, &str_value);
    printf("thread: %lu return %s\n", pthread_self(),
           ((std::string *) pthread_getspecific(pthread_key_))->c_str());
}

void CThreadSpecificData::thread2() {
    printf("thread %lu is running", pthread_self());
    int key_value = 2;
    pthread_setspecific(pthread_key_, reinterpret_cast<void *>(static_cast<intptr_t>(key_value)));
    printf("thread: %lu return %d\n", pthread_self(),
           static_cast<int>(reinterpret_cast<intptr_t>(pthread_getspecific(pthread_key_))));
}

void *CThreadSpecificData::rutin1(void *input_data) {
    CThreadSpecificData *data = (CThreadSpecificData *) input_data;
    data->thread1();
}

void *CThreadSpecificData::rutin2(void *input_data) {
    CThreadSpecificData *data = (CThreadSpecificData *) input_data;
    data->thread2();
}

void CThreadSpecificData::test() {

    printf("test thread: %lu is running int size %lu int* size %lu void* size %lu\n", pthread_self(), sizeof(int),
           sizeof(int *), sizeof(void *));
    pthread_create(&pthread1_, nullptr, rutin1, (void *) this);

    pthread_join(pthread1_, nullptr);
    pthread_join(pthread2_, nullptr);
    int key_value = 0;
    pthread_setspecific(pthread_key_, reinterpret_cast<void *>(static_cast<intptr_t>(key_value)));
    printf("thread: %ld return %d\n", pthread_self(),
           static_cast<int>(reinterpret_cast<intptr_t>(pthread_getspecific(pthread_key_))));

    pthread_key_delete(pthread_key_);
}
