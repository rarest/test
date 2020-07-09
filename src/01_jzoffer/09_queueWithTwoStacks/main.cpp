//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main() {
    LOG(error, "main")

    queue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char val = queue.deleteHead();
    Test(val, 'a');

    queue.appendTail('d');

    val = queue.deleteHead();
    Test(val, 'b');

    val = queue.deleteHead();
    Test(val, 'c');

    val = queue.deleteHead();
    Test(val, 'd');
    queue.appendTail('e');

    val = queue.deleteHead();

    Test(val, 'e');
    queue.deleteHead();

    return 0;
}