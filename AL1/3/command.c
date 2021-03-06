#include <stdio.h>
#include "linked_list.h"

int main(int argc, char* argv[]) {
    LIST list = list_construct();
    POSITION pos = list_first(list);

    for(;;) {
        char buf[256];
        char c;
        int value = 0;
        
        fgets(buf, 256, stdin);
        if(sscanf(buf, "%c %d", &c, &value) == 0) {
            continue;
        }
        switch(c) {
            case 'i':
                list_insert(list, pos, value);
                printf("Insert a value:%d\n", value);
                break;
            case 'd':
                list_delete(list, pos);
                printf("Delete a value\n");
                break;
            case 'r':
                value = list_retrieve(list, pos);
                printf("Retrieve a value:%d\n", value);
                break;
            case 'f':
                pos = list_first(list);
                printf("Move to the top.\n");
                break;
            case 'l':
                pos = list_last(list);
                printf("Move to the tail.\n");
                break;
            case 'n':
                pos = list_next(list, pos);
                printf("Move to the next.\n");
                break;
            case 'p':
                pos = list_previous(list, pos);
                printf("Move to the previous.\n");
                break;
            case 'g':
                pos = list_get(list, value);
                printf("Move to %d\n", value);
                break;
            case 'x':
                //pos = list_index(list, value);
                //printf("Move to the position of %d\n", value);
                break;
        }

        list_print(list);
    }
}