#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int* slot;
}Stack;


void Push(Stack* stack, int value){
    if(stack->top+1 < stack->size){
        stack->top++;
        stack->slot[stack->top] = value;
    }
}

int Pop(Stack* stack){
    if(stack->top >= 0){
        return stack->slot[stack->top--];
    }
}

void Print(Stack* stack){
    printf(" Top = %d \n",stack->top);
    printf("Size = %d \n",stack->size);
    printf("\n");
    printf("ID - Value: \n");

    for(int i=0; i <= stack->top; i++){
        printf("%d - %d\n",i,stack->slot[i]);
    }

    printf("\n###########################\n");
}

int main(void){
    printf("\t Stack \n\n");

    Stack stack = {
        .top = -1,
        .size = 20,
        .slot = (int*)calloc(stack.size, sizeof(int))
    };

    Push(&stack,3);
    Push(&stack,1);
    Push(&stack,9);

    printf("Pop: %d \n\n",Pop(&stack));

    Print(&stack);

    return 0;
}
