/* bubble_sort.c */

#include "sort.h"

void sort(int *list, int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if(list[j] > list[j + 1]) {
                int tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
                for (int k=0; k < length; k++) {
                    if (k==length-1) printf("%d", list[k]);
                    else printf("%d,", list[k]);
                }
                printf("\n");
            }
        }
    }
}