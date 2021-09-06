#include <stdio.h>

extern void swap(int*, int*);
extern void selectionSort(int*, const int size);
extern void printArray(const int*, const int);


int main(){
    int array[] = {5,10,80,6,99,70,64,60,42,23,90,32,68};
    int arraySize = sizeof(array)/sizeof(int);

    printf("Rand Array: ");
    printArray(array,arraySize);

    selectionSort(array, arraySize);

    printf("Sorted Array: ");
    printArray(array,arraySize);

    return 0;
}


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}


void selectionSort(int* array, const int size){
    int minPos;

    for(int i = 0; i < (size-1); i++){
        minPos = i;

        for(int j = i+1; j < size; j++){
            if(array[j] < array[minPos])
                minPos = j;
        }

        if(i != minPos)
            swap(&array[i], &array[minPos]);
    }
}


void printArray(const int* array, const int arrayLength){
    for(int i = 0; i < arrayLength; i++){
        printf("%d",array[i]);

        if(i != arrayLength-1)
            printf(", ");
        else
            printf(". \n\n");
    }
}
