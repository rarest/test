//
// Created by ChenShuQuan on 2021/11/14.
//

#ifndef CPPTEST_CMYSTRING_H
#define CPPTEST_CMYSTRING_H

class CMyString {
public:
    CMyString(const char *str = 0);

    ~CMyString();

    CMyString(const CMyString &str);

    CMyString(CMyString &&str);

    CMyString &operator=(const CMyString &str);

    CMyString &operator=(CMyString &&str);

    char *getData();
public:
    static void reset();
    static int ctorCount;
    static int cctorCount;
    static int mctorCount;
    static int casignCount;
    static int masignCount;

private:
    char *mStrData;
};


#endif //CPPTEST_CMYSTRING_H
