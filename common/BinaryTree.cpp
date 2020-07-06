/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#include <cstdio>
#include "BinaryTree.h"

BinaryTreeNode *CreateBinaryTreeNode(int value) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNode *pNode) {
    if (pNode != nullptr) {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if (pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    } else {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTreePre(const BinaryTreeNode *pRoot) {

    if (pRoot == nullptr) {
        printf("this node is null\n");
        return;
    }
    PrintTreeNode(pRoot);


    if (pRoot->m_pLeft != nullptr)
        PrintTreePre(pRoot->m_pLeft);

    if (pRoot->m_pRight != nullptr)
        PrintTreePre(pRoot->m_pRight);

}

void PrintTreeIn(const BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        printf("this node is null\n");
        return;
    }

    if (pRoot->m_pLeft != nullptr)
        PrintTreeIn(pRoot->m_pLeft);

    PrintTreeNode(pRoot);

    if (pRoot->m_pRight != nullptr)
        PrintTreeIn(pRoot->m_pRight);

}

void PrintTreeEnd(const BinaryTreeNode *pRoot) {
    if (pRoot == nullptr) {
        printf("this node is null\n");
        return;
    }

    if (pRoot->m_pLeft != nullptr)
        PrintTreeEnd(pRoot->m_pLeft);

    if (pRoot->m_pRight != nullptr)
        PrintTreeEnd(pRoot->m_pRight);


    PrintTreeNode(pRoot);
}

void DestroyTree(BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
