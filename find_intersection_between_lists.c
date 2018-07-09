/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-09 01:16:13
 * @modify date 2018-07-09 01:16:13
 * @desc find intersection node between two lists.
*/
#include <stdio.h>
#include "common.h"

ListNode * findIntersectionNodeBetween(ListNode *a, ListNode *b) {
    int lenA = 0, lenB = 0; //lenA and lenB represent the length of the list a and b respectively.
    ListNode *head = a;

    do {
        lenA++;
    } while((head = head->next));

    head = b;

    do {
        lenB++;
    } while((head = head->next));

    ListNode *headA = a;
    ListNode *headB = b;
    
    //move bigger list to the node from which has as same size as the smaller one.
    //because if two lists are intersected, the left nodes are same since the intersected node.
    if(lenA < lenB) {
        int d = lenB - lenA;
        while(d-- && (headB = headB->next)) {}
    } else if(lenA > lenB) {
        int d = lenA - lenB;
        while(d-- && (headA = headA->next)) {}
    }

    do {
        if(headA == headB) {
            return headA;
        }
    } while((headA = headA->next) && (headB = headB->next));

    return NULL;
}

int main() {
    ListNode n0 = { 1 };
    ListNode n1 = { 2 };
    ListNode n2 = { 3 };

    ListNode n3 = { 4 };
    ListNode n4 = { 5 };

    ListNode n5 = { 6 };
    ListNode n6 = { 7 };
    ListNode n7 = { 8 };

    //list a
    n0.next = &n1;
    n1.next = &n2;

    //list b
    n3.next = &n4;

    //intersection node
    n2.next = &n5;
    n4.next = &n5;

    //left nodes
    n5.next = &n6;
    n6.next = &n7;

    ListNode *node = findIntersectionNodeBetween(&n0, &n3);
    if(node) {
        printf("intersection node's value is %d", node->value);
    } else {
        printf("no intersection node found.");
    }

    return 0;
}
