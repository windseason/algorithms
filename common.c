/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-08 11:19:56
 * @modify date 2018-07-08 11:19:56
 * @desc [description]
*/

#include <stdio.h>
#include "common.h"

void printList(const ListNode *head) {
    if(NULL == head) {
        printf("[empty list]");
        return;
    }

    printf("[");
    do {
        printf("%d", head->value);
        if(head->next) {
            printf(",");
        }
    } while((head = head->next));
    printf("]\n");
}