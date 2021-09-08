#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* address;
    unsigned size;
    unsigned allocatedSize;
}array;


extern void allocate(array*, unsigned);
extern void set(array*, unsigned, int);
extern int get(array*, unsigned);
extern void append(array*, int);
extern void merge(array*, array*, array*);
extern void printArray(array* arr);


int main(){
    array myArray;
    allocate(&myArray, 1);

    printf("         size: %d \n", myArray.size);
    printf("allocatedSize: %d \n", myArray.allocatedSize);

    append(&myArray, 1);
    printf("\n         size: %d \n", myArray.size);
    printf("allocatedSize: %d \n", myArray.allocatedSize);

    append(&myArray, 2);
    printf("\n         size: %d \n", myArray.size);
    printf("allocatedSize: %d \n", myArray.allocatedSize);

    append(&myArray, 3);
    printf("\n         size: %d \n", myArray.size);
    printf("allocatedSize: %d \n", myArray.allocatedSize);


    printArray(&myArray);

    return 0;
}


void allocate(array* arr, unsigned size){
    arr->size = size;
    arr->allocatedSize = size*2;
    arr->address = (int*)malloc(arr->allocatedSize*sizeof(int));

    //Initialize all elements with 0
    for(int i = 0; i < size; i++)
        arr->address[i] = 0;
}


void set(array* arr, unsigned position, int value){
    if(position < arr->size)
        arr->address[position] = value;
}


void append(array* arr, int value){
    arr->size++;

    if(arr->size >= arr->allocatedSize){
        array expandedArray;
        allocate(&expandedArray, arr->allocatedSize);

        for(int i = 0; i < arr->allocatedSize; i++){
            set(&expandedArray, i, get(arr, i));
        }
        set(&expandedArray, arr->allocatedSize-1, value);

        *arr = expandedArray;
    }
    else{
        arr->address[arr->size-1] = value;
    }
}


int get(array* arr, unsigned position){
    if(position < arr->allocatedSize)
        return arr->address[position];
}


void merge(array* newArray, array* arrayA, array* arrayB){
    unsigned newSize = arrayA->size + arrayB->size;

    allocate(newArray, newSize);

    for(int i = 0; i < arrayA->size; i++)
        set(newArray, i, get(arrayA, i));

    for(int i = 0; i < arrayB->size; i++)
        set(newArray, i+arrayA->size, get(arrayB, i));
}


void printArray(array* arr){
    for(int i = 0; i < arr->size; i++){
        printf("[%d]", get(arr, i));

        if(i+1 != arr->size)
            printf(", ");
        else
            printf("\n");
    }
}
