#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* address;
    unsigned size;
}array;


extern void allocate(array*, unsigned);
extern void set(array*, unsigned, int);
extern int get(array*, unsigned);
extern array* merge(array*, array*, array*);
extern void printArray(array* arr);


int main(){
    //Create array
    array myArrayA;
    allocate(&myArrayA, 3);

    //Set values
    set(&myArrayA, 0, 50);
    set(&myArrayA, 1, 100);
    set(&myArrayA, 2, 200);
    set(&myArrayA, 4, 300); //Incorrect position it's ignored

    //Print
    printf("Array A: ");
    printArray(&myArrayA);

    //Create another array
    array myArrayB;
    allocate(&myArrayB, 2);
    set(&myArrayB, 0, 400);
    set(&myArrayB, 1, 800);

    printf("Array B: ");
    printArray(&myArrayB);

    //Merge
    array myNewBigArray;
    merge(&myNewBigArray, &myArrayA, &myArrayB);

    printf("\n");
    printf("New Big Array: ");
    printArray(&myNewBigArray);

    //Copy
    myArrayA = myArrayB;
    printf("\n");
    printf("New Array A = Array B: ");
    printArray(&myArrayA);

    return 0;
}


void allocate(array* arr, unsigned size){
    arr->address = (int*)malloc(size*sizeof(int));
    arr->size = size;

    //Initialize all elements with 0
    for(int i = 0; i < size; i++)
        arr->address[i] = 0;
}


void set(array* arr, unsigned position, int value){
    if(position < arr->size)
        arr->address[position] = value;
}


int get(array* arr, unsigned position){
    if(position < arr->size)
        return arr->address[position];
}


array* merge(array* newArray, array* arrayA, array* arrayB){
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
