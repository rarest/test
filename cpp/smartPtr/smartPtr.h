//
// Created by Chen Shuquan on 2020/5/13.
//

#ifndef INTERVIEW_SMARTPTR_H
#define INTERVIEW_SMARTPTR_H

class Counted {
private:
    unsigned int count_;
public:
    Counted():count_(0){}
    virtual ~Counted(){}
    Counted* retain() {
        count_++;
        return this;
    }
    void release() {
        count_--;
        if(count_ == 0){
            delete this;
        }
    }
    int count() {
        return count_;
    }
};

template<class T> class Ref: public Counted {
private:
public:
    T* object_;
    Ref(T *obj):object_(0) {
        reset(obj);
    }
    Ref(const Ref &other):object_(0) {
        reset(other.object_);
    }

    template<class Y>
    Ref(const Ref<Y> &other):object_(0) {
        reset(other.object_);
    };

    ~Ref() {
        if(object_) {
            object_->release();
        }
    }
    void reset(T *o) {
        if(o) {
            o->retain();
        }
        if(object_) {
            object_->release();
        }
        object_ = o;
    }

    Ref& operator=(const T *o) {
        reset(o);
        return *this;
    }

    template<class Y>
    Ref& operator=(Y *o) {
        reset (o);
        return *this;
    }

    Ref& operator=(const Ref &o) {
        reset(o.object_);
        return  *this;
    }

    template<class Y>
    Ref& operator=(const Ref<Y> &other) {
        reset(other.object_);
        return *this;
    }

    T& operator*() {
        return *object_;
    }
    T* operator->() {
        return object_;
    }
    operator T*() {
        return object_;
    }

    bool operator==(const T* that) {
        return object_ == that;
    }
    bool operator==(const Ref &other) {
        return object_== other.object_|| *object_ == *(other.object_);
    }

    template<class Y>
    bool  operator==(const Ref<Y> &other) const {
        return object_ == other.object_ || *object_ == *(other.object_);
    }

    bool operator!=(const T* that) {
        return !(*this == that);
    }
    bool empty() const {
        return object_ == 0;
    }

};

#endif //INTERVIEW_SMARTPTR_H
