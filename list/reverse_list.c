/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-08 01:23:32
 * @modify date 2018-07-08 01:23:32
 * @desc Simple algorithm for reversing a list.
*/

#include <stdio.h>
#include <assert.h>
#include "../common.h"

void reverseList(ListNode **ppHead) {
    ListNode *newHead = NULL, *next = NULL;
    ListNode *head = *ppHead;

    while(head) {
        //save next to temp var.
        next        = head->next;

        //point current element to the newHead to become the new head of the 
        //reversed list. 
        head->next  = newHead;
        newHead     = head;

        //move to next element.
        head        = next;
    }
    
    *ppHead = newHead;
}

//head insertion.
void reverseList2(ListNode **ppHead) {
    ListNode *head = *ppHead, *next = NULL;
    ListNode newhead = {0};

    while(head) {
        next            = head->next;
        head->next      = newhead.next;
        newhead.next    = head;
        head            = next;
    }

    *ppHead = newhead.next;
}

ListNode * reverseListBetween(ListNode *head, int m, int n) {
    assert(m < n);

    ListNode *listHead = head;
    ListNode *newHead   = NULL, 
             *next      = NULL, 
             *pre       = NULL,  //point to the node which is the previous node of the reversion list.
             *tail      = NULL;  //point to the node which is the tail of the reversed list;
    int len = n - m + 1;

    while(m--) {
        //move to the position m - 1;
        pre = head;
        head = head->next;
    }

    tail = head;

    while(len-- && head) {
        next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }

    tail->next = head;
    if(NULL == pre) {
        return newHead;
    }

    pre->next = newHead;
    return listHead;
}

int main() {
    ListNode n0 = { 1 };
    ListNode n1 = { 2 };
    ListNode n2 = { 3 };
    ListNode n3 = { 4 };
    ListNode n4 = { 5 };
    ListNode n5 = { 6 };

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    printf("original list is :\n");
    printList(&n0);
    ListNode *newHead = &n0;
    reverseList2(&newHead);
    printList(newHead);

    ListNode *result = reverseListBetween(newHead, 0, 3);
    printList(result);
    return 0;
}