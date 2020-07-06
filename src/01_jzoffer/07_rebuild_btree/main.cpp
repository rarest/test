//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"


void test() {
    int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    int length = sizeof(preOrder)/sizeof(int);
    BinaryTreeNode *root = rebuild(preOrder, inOrder, length);
    PrintTreePre(root);
    PrintTreeIn(root);
    PrintTreeEnd(root);
}

int main() {
    LOG(error, "main")

    test();
    return 0;
}