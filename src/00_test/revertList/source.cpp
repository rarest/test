//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

ListNode *reverseList(ListNode *head) {
    ListNode *nHead = nullptr;
    ListNode *cur = head;
    while (cur) {
        ListNode *next = cur->m_pNext;
        cur->m_pNext = nHead;
        nHead = cur;
        cur = next;
    }
    return nHead;
}