#include <stdio.h>
#include <inttypes.h>

typedef struct Queue{
    int front;
    int rear;
    int size;
    int* slot;
}Queue;


void Enqueue(Queue* queue, int value){
    if(queue->rear <= queue->size){
        queue->slot[queue->rear] = value;
    }
    else if(queue->front = queue->rear){
        queue->front = 0;
        queue->rear = 0;
        queue->slot[queue->rear] = value;
    }

    if(queue->rear < queue->size){
        queue->rear++;
    }
}

int Dequeue(Queue* queue){
    int aux;

    if(queue->rear >= 0){
        aux = queue->slot[queue->front];
        queue->slot[queue->front++] = 0;

        if(queue->front == queue->rear && queue->rear > 0){
            queue->front = 0;
            queue->rear = 0;
        }

        return aux;
    }
}

void Print(Queue* queue){
    printf("\n###########################\n");
    printf(" Front = %d \n",queue->front);
    printf("  Rear = %d \n",queue->rear);
    printf("  Size = %d \n",queue->size);
    printf("\n");
    printf("ID - Value: \n");

    for(int i = 0; i < queue->size; i++){
        printf("%d - %d\n",i,queue->slot[i]);
    }
}

int main(void){
    printf("\t Queue \n\n");

    Queue queue = {
        .front = 0,
        .rear = 0,
        .size = 3,
        .slot = (int*)calloc(queue.size, sizeof(int))
    };

    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);
    Enqueue(&queue,4);

    Print(&queue);

    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);

    Print(&queue);

    Enqueue(&queue,5);
    Print(&queue);

    return 0;
}
