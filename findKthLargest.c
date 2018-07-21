/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-20 05:58:11
 * @modify date 2018-07-20 05:58:11
 * @desc Given a list, find the kth largest one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * Get random int [min ,max)
 */
int randomInt(const int min, const int max) {
    return min + rand() % (max+1 - min);
}

void swap(int *a, int i, int j) {
    int tmp = a[i];
    a[i]    = a[j];
    a[j]    = tmp;
}

void printInts(const int *a, const int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i != n -1){
            printf(",");
        }
    }
    printf("]\n");
}

void printIntsBetween(const int *a, const int low, const int high) {
    printf("[");
    for(int i = low; i <= high; i++) {
        printf("%d", a[i]);
        if(i != high){
            printf(",");
        }
    }
    printf("]\n");
}

int partition(int *a, const int low, const int high) {
    const int n = high - low + 1;
    int index = randomInt(low, high);
    //printf("index is %d\n",index);
    
    //swap the random one with the last one.
    swap(a, index, high);
    int pivot = a[high];
    int i = low, j = high;

    //printIntsBetween(a, low, high);

    while(i < j) {
        //move on if smaller one found.
        while(i < j && a[i] <= pivot) {
            i++;
        }
        
        //copy the greater value to the high region.
        //it is safe to copy smaller one to a[j] because
        //the value of a[j] is stored in pivot at the beginning.
        //after copy, a[j] and a[i] are same.
        a[j] = a[i];

       //move on if greater one found. 
        while(i < j && a[j] >= pivot) {
            j--;
        }

        //copy the smaller value to the small region.
        a[i] = a[j];
    }

    a[i] = pivot;
    //printf("pivot is %d\n", pivot);
    return i;
}

int findKthMax(const int *a, const int n, const int kth) {
    int *tmp = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        tmp[i] = a[i];
    }

    int k = kth;
    int low = 0, high = n -1;
    int result = -1;

    do {
        //printf("\n");

        //printf("k is %d\n", k);
        int mid = partition(tmp, low, high);
        //printf("mid is %d\n", mid);
        //printInts(tmp, n);

        int p = high + 1 - k;
        //printf("p is %d\n", p);
        if(mid == p) {
            result = tmp[mid];
            break;
        }

        if(mid > p) {
            k = k - (high - mid + 1);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } while(low <= high);

    free(tmp);

    return result;
}

#define M_LEN 8

int main() {
    srand((unsigned)time(NULL));
    int a[M_LEN] = {10, 3, 7, 9, 11, 7, 8, 2};
    printf("list is : \n");
    printInts(a, M_LEN);
    // int pivot = partition(a, 0, M_LEN -1);
    // printInts(a, M_LEN);

    const int k = 5;
    const int val = findKthMax(a, M_LEN, k);
    printf("\nthe %dth largest number is %d \n", k, val);
    return 0;
}