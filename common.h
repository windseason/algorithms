/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-08 11:17:47
 * @modify date 2018-07-08 11:17:47
 * @desc Specify methods, types are shared in the projects.
*/

#ifndef __COMMON_H_
#define __COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct listNode {
    int value;
    struct listNode *next;
} ListNode;

void printList(const ListNode *head);

#ifdef __cplusplus
}
#endif 

#endif