#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

typedef struct{
    int buffer[SIZE];
    int tail;
    int head;
    int count;
} circularBuffer;
bool enqueue(circularBuffer *cb, int value);
bool dequeue(circularBuffer *cb, int *value);
void printBuffer(circularBuffer *cb);
bool isEmpty(circularBuffer *cb);
bool isFull(circularBuffer *cb);

int main(){
    circularBuffer cb;
    cb.head = 0;
    cb.tail = 0;
    cb.count = 0;

    for(int i=0;i<8; i++){
        if (enqueue(&cb, i)){
            printf("enqueued %d\n", i);
        }
        else
            printf("buffer full...");
    }

    printBuffer(&cb);

    int val;
    for(int i = 0; i < 3; i++){
        if(dequeue(&cb, &i)){
            printf("dequeued %d", i);
        }
    }

    printBuffer(&cb);

    enqueue(&cb, 99);
    enqueue(&cb, 100);
    printBuffer(&cb);

    return 0;
}

bool isFull(circularBuffer *cb){
    return cb->count == SIZE;
}
bool isEmpty(circularBuffer *cb){
    return cb->count == 0;
}
bool enqueue(circularBuffer *cb, int value){
    if(isFull(cb)){
        return false; //for buffer overflo
    }
    cb -> buffer[cb->head] = value;
    cb -> head = (cb->head + 1) % SIZE;
    cb -> count++;
    return true;
}

bool dequeue(circularBuffer *cb, int *value){
    if(isEmpty(cb)){
        return false;
    }
    *value = cb->buffer[cb->tail];
    cb-> tail = (cb->tail + 1) % SIZE;
    cb-> count--;
    return true;
}

void printBuffer(circularBuffer *cb){
    printf("buffer: ");
    for (int i =0; i < cb->count; i++){
        int index = (cb->tail + i) % SIZE;
        printf("%d", cb->buffer[index]);
    }
    printf("\n");
}