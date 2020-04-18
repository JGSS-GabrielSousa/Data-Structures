#include <stdio.h>

typedef struct Node{
    struct Node* next;
    int value;
}Node;

typedef struct LinkedList{
    int numberOfNodes;
    struct Node* first;
}LinkedList;

void Append(LinkedList* list, int value){
    Node* aux = (Node*)malloc(sizeof(Node));
    aux->value = value;
    aux->next = NULL;

    if(list->numberOfNodes > 0){
        Node* pointer = list->first;

        while(pointer->next != NULL){
            pointer = pointer->next;
        }

        pointer->next = aux;
        list->numberOfNodes = list->numberOfNodes + 1;
    }else{
        list->first = aux;
        list->numberOfNodes = list->numberOfNodes + 1;
    }
}

void PrintList(LinkedList* list){
    int i = 0;
    Node* node;

    printf("The list have %d nodes \n",list->numberOfNodes);

    if(list->numberOfNodes > 0){
        node = list->first;

        printf("ID = Value \n",i++,node->value);
        while(1){
            printf("%d = %d \n",i++,node->value);

            if(node->next != NULL)
                node = node->next;
            else
                return;
        }
    }
}

int main(void){
    printf("\t Singly Linked List \n\n");

    LinkedList list = {.numberOfNodes = 0};

    Append(&list,5);
    Append(&list,10);
    Append(&list,15);

    PrintList(&list);

    return 0;
}
