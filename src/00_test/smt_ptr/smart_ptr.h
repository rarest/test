//
// Created by ChenShuQuan on 2021/11/24.
//

#ifndef CPPTEST_SMART_PTR_H
#define CPPTEST_SMART_PTR_H

#include "common.h"


//https://blog.csdn.net/RaKiRaKiRa/article/details/94991797
//https://blog.csdn.net/daxiang10m/article/details/106246839

template<class T>
class CSharedPtr {
public:
    CSharedPtr() : ptr_(nullptr), count_(new size_t) { *count_ = 0; }

    CSharedPtr(T *ptr) : ptr_(ptr), count_(new size_t) { *count_ = 1; }

    ~CSharedPtr() {
        release();
    }


    CSharedPtr(const CSharedPtr &ptr) : count_(&(++(*ptr.count_))), ptr_(ptr.ptr_) {
    }


    CSharedPtr &operator=(const CSharedPtr &ptr) {
        if (this != &ptr) {
            release();
            count_ = &(++*ptr.count_);
            ptr_ = ptr.ptr_;
        }
        return *this;
    }

    CSharedPtr(CSharedPtr &&ptr) : ptr_(ptr.ptr_), count_(ptr.count_) {
        ptr.ptr_ = nullptr;
        ptr.count_ = nullptr;

    }

    CSharedPtr &operator=(CSharedPtr &&ptr) noexcept {
        release();
        ptr_ = ptr.ptr_;
        count_ = ptr.count_;
        ptr.ptr_ = nullptr;
        ptr.count_ = nullptr;
        return *this;
    }

    T &operator*() const {
        return *ptr_;
    }

    T *operator->() {
        return ptr_;
    };

    T *get() {
        return ptr_;
    }

    operator bool() {
        return ptr_ != nullptr;
    }

    size_t useCount() {
        return count_ == nullptr ? 0 : *count_;
    }


private:
    void release() {
        if (count_ == nullptr && ptr_ == nullptr) {
            return;
        }
        --(*count_);
        if (*count_ == 0) {
            delete count_;
            delete ptr_;
            count_ = nullptr;
            ptr_ = nullptr;
        }
    }


private:
    T *ptr_;
    size_t *count_;
};

template<class T>
class CUniquePtr {
public:
    explicit CUniquePtr(T *ptr) : ptr_(ptr) {}

    ~CUniquePtr() {
        if (ptr_) {
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    CUniquePtr(const CUniquePtr &ptr) = delete;

    CUniquePtr &operator=(const CUniquePtr &ptr) = delete;

    CUniquePtr(CUniquePtr &&ptr) noexcept;

    CUniquePtr &operator=(CUniquePtr &&ptr) noexcept;

    T &operator*() const {
        return *ptr_;
    }

    T *operator->() const {
        return ptr_;
    }

    void swap(CUniquePtr &ptr) noexcept {
        std::swap(ptr_, ptr, ptr_);
    }

private:
    T *ptr_;
};

template<class T>
CUniquePtr<T>::CUniquePtr(CUniquePtr &&ptr) noexcept:ptr_(ptr.ptr_) {
    ptr.ptr_ = nullptr;
}


template<class T>
CUniquePtr<T> &CUniquePtr<T>::operator=(CUniquePtr &&ptr) noexcept {
    swap(ptr);
    return *this;
}

#endif //CPPTEST_SMART_PTR_H
