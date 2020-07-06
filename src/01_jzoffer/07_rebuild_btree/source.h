//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"
#include "BinaryTree.h"

BinaryTreeNode* rebuildCore( int* startPreOrder,  int * endPreOrder, int* startInOrder,  int* endInOrder);

BinaryTreeNode* rebuild(int* preOrder, int*middleOrder, int length);

#endif //INTERVIEW_SOURCE_H
