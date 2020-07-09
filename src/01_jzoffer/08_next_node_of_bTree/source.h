//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

//#include "common.h"

struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
    BinaryTreeNode*        m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode);
BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectBinaryTreeNode(BinaryTreeNode* parent, BinaryTreeNode *pLeft, BinaryTreeNode* pRight);
void PrintBinaryTreeNode(BinaryTreeNode * node);




#endif //INTERVIEW_SOURCE_H
