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


void Delete(LinkedList* list, int position){
    if(position < 0 || position > list->numberOfNodes)
        return;

    if(position == 1){
        Node* pointer = list->first;
        if(list->numberOfNodes == 1)
            list->first = NULL;
        else
            list->first = list->first->next;
        free(pointer);
        list->numberOfNodes--;

        return;
    }

    Node* pointer = list->first;
    Node* previous;

    for(int i = 0; i<position; i++){
        pointer = pointer->next;

        if(i == position-2)
            previous = pointer;
    }
    previous->next = pointer->next;

    free(pointer);
    list->numberOfNodes--;
}


void PrintList(LinkedList* list){
    int i = 0;
    Node* node;
    Node** pointer;
    LinkedList** llPointer = &list;

    int listBytesSize = list->numberOfNodes*sizeof(Node) + sizeof(**llPointer);

    printf("The list have %d nodes, occupying %d bytes, %.1f bytes per node\n\n",list->numberOfNodes,listBytesSize,(float)listBytesSize/list->numberOfNodes);

    if(list->numberOfNodes > 0){
        node = list->first;

        printf("ID = Value -> Value of Next | Addresses \n\n");
        while(1){
            printf("%d = %d ",i++,node->value);

            if(node->next != NULL){
                printf("-> %d \t",node->next->value);
                pointer = &node;
                printf("| %x -> ",*pointer);
                pointer = &node->next;
                printf("%x \n",*pointer);
                node = node->next;
            }
            else{
                printf("-> NULL \t");
                pointer = &node;
                printf("| %x -> NULL \n",*pointer);
                break;
            }
        }
    }

    printf("####################################\n");
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
    Delete(&list,2);

    PrintList(&list);

    return 0;
}
