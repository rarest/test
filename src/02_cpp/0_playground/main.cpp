//
// Created by ChenShuQuan on 2021/12/21.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *reverseList(ListNode *head) {
    ListNode *h = nullptr;
    while (head) {
        ListNode *next = head->next;
        next->next = h;
        h = head;
        head = next;
    }
    return h;
}

class CString {
public:
    explicit CString(const char *str);

    ~CString();

    CString(const CString &cString);

    CString(CString &&cString) noexcept;

    CString &operator=(const CString &cString);

    CString &operator=(CString &&cString) noexcept;

    const char *get() { return str_; }

private:
    char *str_;
};


CString::CString(const char *str) {
    str_ = new char[strlen(str) + 1];
    strcpy(str_, str);
}

CString::~CString() {
    delete[] str_;
    str_ = nullptr;
}

CString::CString(const CString &cString) {
    str_ = new char[strlen(cString.str_) + 1];
    strcpy(str_, cString.str_);
}

CString::CString(CString &&cString) noexcept: str_(cString.str_) {
    cString.str_ = nullptr;
}

CString &CString::operator=(const CString &cString) {
    if (this == &cString) {
        return *this;
    }
    CString tmp(cString);
    std::swap(str_, tmp.str_);
    return *this;
}

CString &CString::operator=(CString &&cString) noexcept {
    delete[] str_;
    str_ = cString.str_;
    cString.str_ = nullptr;
}

