#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    int value;
}Node;

typedef struct LinkedList{
    int numberOfNodes;
    struct Node* first;
}LinkedList;


void Append(LinkedList* list, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if(list->numberOfNodes > 0){
        Node* pointer = list->first;

        while(pointer->next != NULL){
            pointer = pointer->next;
        }

        pointer->next = newNode;
    }else{
        list->first = newNode;
    }

    list->numberOfNodes++;
}


void Prepend(LinkedList* list, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->first;

    list->first = newNode;
    list->numberOfNodes++;
}


void PrintList(LinkedList* list){
    int i = 0;
    Node* node;

    printf("The list have %d nodes \n\n",list->numberOfNodes);

    if(list->numberOfNodes > 0){
        node = list->first;

        printf("ID = Value -> Value of Next \n\n",i++,node->value);
        while(1){
            printf("%d = %d ",i++,node->value);

            if(node->next != NULL){
                printf("-> %d \n",node->next->value);
                node = node->next;
            }
            else{
                printf("-> NULL \n");
                return;
            }
        }
    }
}


int main(void){
    printf("\t Singly Linked List \n\n");

    LinkedList list = {
        .numberOfNodes = 0,
        .first = NULL
    };

    Append(&list,10);
    Append(&list,15);
    Append(&list,20);
    Prepend(&list,5);

    PrintList(&list);

    return 0;
}
