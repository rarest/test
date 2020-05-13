#include "24_reverseList.h"

BEGIN_INTERVIEW_NS
    SListNode *reverseList(SListNode *header) {
        PSListNode idx = header;
        PSListNode pHeader = nullptr;
        while (idx) {
            PSListNode pNext = idx->next;
            idx->next = pHeader;
            pHeader = idx;
            idx = pNext;
        }
        return pHeader;
    }

    SListNode *createList(int count) {
        SListNode *header = nullptr;
        count = min(count, 10);
        for (int i = count - 1; i >= 0; i--) {
            SListNode *pSListNode = new SListNode;
            pSListNode->val = i;
            pSListNode->next = header;
            header = pSListNode;
        }
        return header;
    }

    void printListNode(SListNode *header) {
        SListNode *idx = header;
        while (idx) {
            printf("%d", idx->val);
            if (idx->next) {
                printf("->");
            }
            idx = idx->next;
        }
        printf("\n");
    }

    void deleteListNode(SListNode *header) {
        SListNode *idx = header;
        while (idx) {
            SListNode *next = idx->next;
            printf("del %d ", idx->val);
            delete idx;
            idx = next;
        }
        printf("\n");
    }


END_INTERVIEW_NS