//
// Created by Chen Shuquan on 2020/5/14.
//

#ifndef INTERVIEW_MAXQUEUE_H
#define INTERVIEW_MAXQUEUE_H

#include <queue>;

/**
 *  O(1）for max pop push
 * @tparam T
 */
template<class T>
class MaxQueue {
public:
    MaxQueue();

    ~MaxQueue();

public:
    void push_back(T val);

    T front();

    void pop_front();

    T max() const;

private:
    struct InternalData {
        int idx;
        T val;
    };

    std::deque<InternalData> mDequeData;
    std::deque<InternalData> mDequeIdx;

    int mNCurIndex;
};


template<class T>
MaxQueue<T>::MaxQueue():mNCurIndex(0) {

}

template<class T>
MaxQueue<T>::~MaxQueue() {
    mDequeData.clear();
    mDequeIdx.clear();
}

template<class T>
void MaxQueue<T>::push_back(T val) {
    InternalData data{mNCurIndex++, val};

    while (!mDequeIdx.empty() && val >= mDequeIdx.back().val) {
        mDequeIdx.pop_back();
    }

    mDequeIdx.push_back(data);
    mDequeData.push_back(data);
}

template<class T>
T MaxQueue<T>::front() {
    if (mDequeData.empty()) throw std::runtime_error("queue is empty");
    return mDequeData.front().val;
}


template<class T>
void MaxQueue<T>::pop_front() {
    if (mDequeIdx.empty()) throw std::runtime_error("queue is empty");
    if (mDequeData.front().idx == mDequeIdx.front().idx) mDequeIdx.pop_front();

    mDequeData.pop_front();
}

template<class T>
T MaxQueue<T>::max() const {
    if (mDequeIdx.empty()) throw std::runtime_error("queue is empty");
    return mDequeIdx.front().val;
}


#endif //INTERVIEW_MAXQUEUE_H
