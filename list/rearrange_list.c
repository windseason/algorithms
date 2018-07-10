/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-10 12:40:41
 * @modify date 2018-07-10 12:40:41
 * @desc given a list head and a specific node with certain value, rearrange the list to have nodes whose values are smaller than the specific 
 * value positioned ahead of the node which holds the given value. Pls make sure the relevant order of these nodes in the rearranged list
 * keep as same as before arrangement.
*/

#include <stdio.h>
#include "../common.h"

ListNode * arrange(ListNode *head, const int value) {
    ListNode small;
    ListNode big;
    ListNode equal;    
    ListNode *pSmall = &small, *pBig = &big, *pEqual = &equal, *current = head;
    
    while(current) {
        ListNode *next = current->next;
        current->next = NULL;

        int currentValue = current->value;
        if(currentValue < value) {
            pSmall->next = current;
            pSmall = pSmall->next;
        } else if(currentValue == value) {
            pEqual->next = current;
            pEqual = pEqual->next;
        } else {
            pBig->next = current;
            pBig = pBig->next;
        }

        current = next;
    }
    
    //specific value not found.
    if(NULL == equal.next) {
        return NULL;
    }

    pSmall->next = equal.next;
    pEqual->next = big.next;
    return small.next;
}

int main() {
    ListNode n0 = { 4 };
    ListNode n1 = { 5 };
    ListNode n2 = { 3 };
    ListNode n3 = { 1 };
    ListNode n4 = { 2 };
    ListNode n5 = { 2 };
    ListNode n6 = { 5 };
    ListNode n7 = { 5 };

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    ListNode *result = arrange(&n0,4);
    if(result) {
        printList(result);
    } else {
        printf("specific value not found in the list\n");
    }

    return 0;
}