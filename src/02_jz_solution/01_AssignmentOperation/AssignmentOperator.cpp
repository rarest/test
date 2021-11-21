//
// Created by ChenShuQuan on 2021/11/14.
//

#include<cstring>
#include<cstdio>
class CString {
public:
    CString(char *pData = nullptr);

    CString(const CString &str);

    CString(CString &&str);

    ~CString();

    CString &operator=(const CString &str);

    CString &operator=(CString &&str);

    void Print();

private:
    char *m_pData;
};

CString::CString(char *pData) {
    if (pData == nullptr) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    } else {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CString::CString(const CString &str) {
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CString::CString(CString &&str) : m_pData(str.m_pData) {
    str.m_pData = nullptr;
}

CString::~CString() {
    delete[] m_pData;
}

CString &CString::operator=(const CString &str) {
    if (this == &str)
        return *this;
    //保证异常安全，如果分配空间失败，该实例保持之前的状态。
    CString tmp(str);
    char *tmpData = tmp.m_pData;
    tmp.m_pData = this->m_pData;
    this->m_pData = tmpData;
    return *this;
//    delete []m_pData;
//    m_pData = nullptr;//
//    m_pData = new char[strlen(str.m_pData) + 1];
//    strcpy(m_pData, str.m_pData);//
//    return *this;
}

CString &CString::operator=(CString &&str) {
    if (&str == this)
        return *this;
    delete[]m_pData;
    m_pData = str.m_pData;
    str.m_pData = nullptr;

    return *this;
}


void CString::Print() {
    printf("%s", m_pData);
}

void Test1() {
    printf("Test1 begins:\n");

    char *text = "Hello world";

    CString str1(text);
    CString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}


void Test2() {
    printf("Test2 begins:\n");

    char *text = "Hello world";

    CString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}


void Test3() {
    printf("Test3 begins:\n");

    char *text = "Hello world";

    CString str1(text);
    CString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char *argv[]) {
    Test1();
    Test2();
    Test3();

    return 0;
}
