/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-09 11:07:41
 * @modify date 2018-07-09 11:07:41
 * @desc check if there is a ring in the given list.
*/

#include <stdio.h>
#include <stdbool.h>
#include "../common.h"

bool checkRing(ListNode *head) {
    ListNode *slow = head, *fast = head->next;

    while(slow && fast) {
        if(slow == fast) {
            return true;
        }

        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
    }
    return false;
}


int main() {
    ListNode n0 = { 2 };
    ListNode n1 = { 4 };
    ListNode n2 = { 6 };

    ListNode n3 = { 1 };
    ListNode n4 = { 2 };
    ListNode n5 = { 3 };

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    // n5.next = &n2;

    bool ringFound = checkRing(&n0);
    printf("is there is a ring in the list?  %s", ringFound ? "yes" : "no");

    return 0;
}