//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

int main() {

    ListNode *node1 = CreateListNode(1);
    ListNode *node2 = CreateListNode(2);
    ListNode *node3 = CreateListNode(3);
    ListNode *node4 = CreateListNode(4);
    ListNode *node5 = CreateListNode(5);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);

    PrintList(node1);

    ListNode *node = reverseList(node1);

    PrintList(node);

    LOG(error, "main")
    return 0;
}