#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUCKETS 10

struct Node{
   char data[100];
   struct Node* next;
};

struct Node* hashTable[BUCKETS];

extern unsigned simpleHashFunc(char*, const char);
extern void insert(char*);
extern void clearHashTable();
extern void hashTableDebug();
extern void hashDebug(char* input);


int main(){
    char input[100];
    clearHashTable();

    hashDebug("hello");
    hashDebug("world");

    insert("hello");
    insert("world");
    insert("i");
    insert("love");
    insert("programming");
    insert("123");
    insert("321");
    insert("abc");
    insert("xyz");

    hashTableDebug();

    return 0;
}


unsigned simpleHashFunc(char* input, const char typeOfReturn){
    unsigned hashValue;

    for(hashValue = 0; *input != '\0'; input++)
        hashValue = *input + 17*hashValue;

    if(typeOfReturn == 0)
        return hashValue % BUCKETS;
    else
        return hashValue;
}


void hashDebug(char* input){
    printf("%s = %d \n", input, simpleHashFunc(input, 1));
}


void insert(char data[]){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node;
    struct Node* aux;

    strcpy(newNode->data, data);
    newNode->next = NULL;

    char collision = 0;
    int index = simpleHashFunc(data, 0);


    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    }
    else{
        collision = 1;
        node = hashTable[index];

        if(node->next == NULL){
            node->next = newNode;
        }
        else{
            aux = node->next;
            node->next = newNode;
            newNode->next = aux;
        }
    }
}


void clearHashTable(){
    for(int i = 0; i < BUCKETS; i++){
        hashTable[i] = NULL;
    }
}


void hashTableDebug(){
    float fill = 0;
    struct Node* aux;

    for(int i = 0; i < BUCKETS; ++i){
        printf("Bucket [%d]: ",i);

        if(hashTable[i] != NULL){
            fill++;
            printf("%s", hashTable[i]->data);

            if(hashTable[i]->next != NULL){
                printf(",");
                aux = hashTable[i]->next;
                while(1){
                    printf(" %s", aux->data);

                    if(aux->next != NULL){
                        printf(",");
                        aux = aux->next;
                    }
                    else{
                        printf("\n");
                        break;
                    }
                }
            }
            else{
                printf("\n");
            }
        }
        else{
            printf("\n");
        }
    }

    printf("\n");
    printf("Bucket fill ratio: %.1f%% \n", (fill/BUCKETS)*100);
}
