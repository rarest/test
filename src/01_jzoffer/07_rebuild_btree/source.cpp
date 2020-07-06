//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

BinaryTreeNode *rebuildCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder) {
    auto *root = new BinaryTreeNode();
    root->m_nValue = startPreOrder[0];
    root->m_pLeft = root->m_pRight = nullptr;

    if (startPreOrder == endPreOrder) {
        if (startInOrder == endInOrder && *startPreOrder == *startInOrder) {
            return root;
        } else {
            throw std::invalid_argument("has one element but not equal");
        }
    }

    int *rootInOrder = startInOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != startPreOrder[0]) {
        rootInOrder++;
    }
    if (rootInOrder == endInOrder && *rootInOrder != startPreOrder[0]) {
        throw std::invalid_argument("can't find root in inOrder");
    }
    int leftChildLen = rootInOrder - startInOrder;

    if (rootInOrder > startInOrder) {
        root->m_pLeft = rebuildCore(startPreOrder + 1, startPreOrder + leftChildLen, startInOrder, rootInOrder - 1);
    }
    if (rootInOrder < endInOrder) {
        root->m_pRight = rebuildCore(startPreOrder + leftChildLen + 1, endPreOrder, rootInOrder + 1, endInOrder);
    }
    return root;
}

BinaryTreeNode *rebuild(int *preOrder, int *inOrder, int length) {
    if (!preOrder || !inOrder || length < 1)
        return nullptr;
    return rebuildCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}


