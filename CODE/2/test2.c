#include <stdio.h>

void main() {
    int P;
    for (int i=0; i<26; i++) {
        scanf("%d", &P);
        printf("%c", P+96);
    }
}