#include <iostream>
#include "24_reverseList.h"

USE_INTERVIEW_NS

int main() {
    SListNode *header = createList(10);
    printListNode(header);
    header = reverseList(header);
    printListNode(header);
    deleteListNode(header);
}