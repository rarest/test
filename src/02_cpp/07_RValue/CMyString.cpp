//
// Created by ChenShuQuan on 2021/11/14.
//

#include "CMyString.h"
#include "common.h"

int CMyString::ctorCount = 0;
int CMyString::cctorCount = 0;
int CMyString::mctorCount = 0;
int CMyString::casignCount = 0;
int CMyString::masignCount = 0;

void CMyString::reset() {
    CMyString::ctorCount = 0;
    CMyString::cctorCount = 0;
    CMyString::mctorCount = 0;
    CMyString::casignCount = 0;
    CMyString::masignCount = 0;
}

char *CMyString::getData() {
    return mStrData;
}

CMyString::CMyString(const char *str) {
    Log("ctor");
    ctorCount++;
    if (str == nullptr) {
        mStrData = new char[1];
        mStrData[0] = '\0';
    } else {
        mStrData = new char[strlen(str) + 1];
        strcpy(mStrData, str);
    }
}

CMyString::~CMyString() {
    Log("dtor");
    delete[] mStrData;
}

CMyString::CMyString(const CMyString &str) {
    Log("cctor");
    cctorCount++;
    if (&str == this)
        return;
    mStrData = new char[strlen(str.mStrData) + 1];
    strcpy(mStrData, str.mStrData);

}

CMyString::CMyString(CMyString &&str) : mStrData(str.mStrData) {
    Log("mctor");
    mctorCount++;
    str.mStrData = nullptr;
}

CMyString &CMyString::operator=(const CMyString &str) {
    Log("casign");
    casignCount++;
    if (&str == this)
        return *this;
#if 0
    CMyString tmpStr(str);
    char *tmpData = tmpStr.mStrData;
    tmpStr.mStrData = mStrData;
    mStrData = tmpData;
#else
    delete[] mStrData;
    mStrData = new char[strlen(str.mStrData) + 1];
    strcpy(mStrData, str.mStrData);
#endif
    return *this;
}

CMyString &CMyString::operator=(CMyString &&str) {
    Log("masign");
    masignCount++;
    delete[] mStrData;
    mStrData = str.mStrData;
    str.mStrData = nullptr;
    return *this;
}
