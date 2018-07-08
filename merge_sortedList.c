/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-08 11:16:45
 * @modify date 2018-07-08 11:16:45
 * @desc merge two sorted list into one list.
*/

#include <stdio.h>
#include <assert.h>
#include "common.h"

ListNode * mergeSortedLists(ListNode *a, ListNode *b) {
    ListNode newHead;
    ListNode *pre = &newHead;

    while(a && b) {
        if(a->value < b->value) {
            pre->next = a;
            a = a->next;
        } else {
            pre->next = b;
            b = b->next;
        }

        pre = pre->next;
    }

    if(a) {
        pre->next = a;
    }

    if(b) {
        pre->next = b;
    }

    return newHead.next;
}

int main() {
    ListNode n0 = { 2 };
    ListNode n1 = { 4 };
    ListNode n2 = { 6 };

    ListNode n3 = { 1 };
    ListNode n4 = { 2 };
    ListNode n5 = { 3 };
    ListNode n6 = { 5 };

    n0.next = &n1;
    n1.next = &n2;

    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode *mergedList = mergeSortedLists(&n0, &n3);
    printList(mergedList);

    return 0;
}

