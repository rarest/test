//
// Created by Chen Shuquan on 2021/12/14.
//

#include <iostream>

struct ListNode {
    int val;
    int idx;
    char *data;
    ListNode *next;

    ListNode() : ListNode(0, nullptr) {
        idx = 0;
        data = nullptr;
    }

    ListNode(int data_, ListNode *next_) : val(data_), next(next_) {}
};

void printNodes(ListNode *node) {
    printf("%d %d %p %p\n", node->val, node->idx, node->data, node->next);
}

int main() {
    int array[10];
    ListNode nodes[3];
    ListNode node1;
    printNodes(&node1);
    printf("%d\n", array[5]);
    for (int i = 0; i < 3; i++) {
        printNodes(&nodes[i]);
    }
}