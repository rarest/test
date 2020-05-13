#ifndef INTERVIEW_24_REVERSELIST_H
#define INTERVIEW_24_REVERSELIST_H

#include "common.h"

BEGIN_INTERVIEW_NS

SListNode* reverseList(SListNode* header);

SListNode* createList(int count);

void printListNode(SListNode* header);

void deleteListNode(SListNode* header);

END_INTERVIEW_NS

#endif