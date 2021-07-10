#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    int value;
}Node;

typedef struct LinkedList{
    int numberOfNodes;
    struct Node* first;
}LinkedList;

extern void Append(LinkedList*, int);
extern void Prepend(LinkedList*, int);
extern void Delete(LinkedList*, int);
extern void PrintNode(Node*);
extern void PrintList(LinkedList*);
extern Node* Search(LinkedList*, int);


int main(void){
    printf("\t Doubly Linked List \n\n");

    LinkedList list = {
        .numberOfNodes = 0,
        .first = NULL
    };

    Append(&list,15);
    Append(&list,20);
    Append(&list,25);
    Append(&list,30);
    Prepend(&list,10);
    Prepend(&list,5);
    // Expected: 5-10-15-20-25-30

    PrintList(&list);
    Delete(&list,0);
    Delete(&list,2);
    // Expected: 10-15-25-30

    //PrintNode(Search(&list,25));

    PrintList(&list);

    return 0;
}


void Append(LinkedList* list, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(list->numberOfNodes > 0){
        Node* pointer = list->first;

        while(pointer->next != NULL){
            pointer = pointer->next;
        }

        pointer->next = newNode;
        newNode->prev = pointer;
    }else{
        list->first = newNode;
    }

    list->numberOfNodes++;
}


void Prepend(LinkedList* list, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->first;
    newNode->prev = NULL;

    list->first->prev = newNode;
    list->first = newNode;

    list->numberOfNodes++;
}


void Delete(LinkedList* list, int position){
    Node* pointer = list->first;
    Node* previous;

    if(position < 0 || position > list->numberOfNodes)
        return;

    if(position == 0){
        if(list->numberOfNodes == 1)
            list->first = NULL;
        else{
            list->first = list->first->next;
            list->first->prev = NULL;
        }
        free(pointer);
        list->numberOfNodes--;
        return;
    }

    for(int i = 0; i < position; i++){
        pointer = pointer->next;

        if(i == position - 2)
            previous = pointer;
    }
    previous->next = pointer->next;

    free(pointer);
    list->numberOfNodes--;
}


Node* Search(LinkedList* list, int value){
    Node* pointer = list->first;

    for(int i = 0; i < list->numberOfNodes; i++)
        if(pointer->value == value)
            break;

    return pointer;
}


void PrintList(LinkedList* list){
    int i = 0;
    Node* node;
    Node** pointer;
    LinkedList** llPointer = &list;

    int listBytesSize = list->numberOfNodes*sizeof(Node) + sizeof(**llPointer);

    printf("####################################\n");
    printf("The list have %d nodes, occupying %d bytes, %.1f bytes per node\n\n",list->numberOfNodes,listBytesSize,(float)listBytesSize/list->numberOfNodes);

    if(list->numberOfNodes > 0){
        node = list->first;

        printf("ID = Value | Prev -> Address -> Next \n\n");
        while(1){
            printf("%d = %d ", i++, node->value);

            if(node->prev != NULL){
                printf("| %x -> ",&node->prev);
                printf("%x -> ",&*node);
            }
            else
                printf("| NULL -> %x -> ",&node);


            if(node->next != NULL){
                printf("%x \n",*&node->next);
                node = node->next;
            }
            else{
                printf("NULL \n");
                break;
            }
        }
    }
}


void PrintNode(Node* node){
    printf("####################################\n");
    printf("       Value: %d \n",node->value);
    printf("     Address: %x \n",node);
    printf("Prev Address: %x \n",node->prev);
    printf("Next Address: %x \n",node->next);
}

