//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include "List.h"

void printListNodeFromEnd(ListNode *head) {

    if (head) {
        ListNode *next = head->m_pNext;
        if (head->m_pNext) {
            printListNodeFromEnd(next);
        }
        PrintListNode(head);
    }
}
