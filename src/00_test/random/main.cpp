#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
    std::cout << "Hello, World!" << std::endl;
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);//随机数分布对象
    for (int i = 0; i < 10; i++)  //生成范围为0-9的随机数序列
    {
        printf("idx %d val %u \n", i, u(e));
    }
    return 0;
}