#include <stdio.h>
#include "list_queue.h"

int main(int argc, char* argv[]) {
    QUEUE queue = queue_construct();

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
                queue_enqueue(queue, value);
                printf("enqueue:%d\n", value);
                break;
            case 'd':
                value = queue_dequeue(queue);
                printf("dequeue:%d\n", value);
                break;
            case 'r':
                value = queue_front(queue);
                printf("front:%d\n", value);
                break;
            case 'k':
                queue_pushfront(queue, value);
                printf("push front:%d\n", value);
                break;
            case 'h':
                value = queue_popback(queue);
                printf("pop back:%d\n", value);
                break;
        }

        queue_print(queue);
    }
}