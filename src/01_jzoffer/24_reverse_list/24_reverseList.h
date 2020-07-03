#ifndef INTERVIEW_24_REVERSELIST_H
#define INTERVIEW_24_REVERSELIST_H

#include "common.h"

BEGIN_INTERVIEW_NS

/**
 *  0->1->2->3->4->5->6->7->8->9 => 9->8->7->6->5->4->3->2->1->0
 * @param header
 * @return
 */

SListNode* reverseList(SListNode* header);

SListNode* createList(int count);

void printListNode(SListNode* header);

void deleteListNode(SListNode* header);

END_INTERVIEW_NS

#endif