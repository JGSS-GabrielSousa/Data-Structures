#include <stdio.h>

void InsertionSort(int* array, const int arrayLength){
    int i, j, x;

    for(i = 1; i < arrayLength; i++){
        x = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > x){
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = x;
    }
}

void PrintArray(const int* array, const int arrayLength){
    for(int i = 0; i < arrayLength; i++){
        printf("%d",array[i]);

        if(i != arrayLength-1)
            printf(", ");
        else
            printf(". \n\n");
    }
}

int main(){
    int array[] = {5,10,80,6,99,70,64,60,42,23,90,32,68};
    int arraySize = sizeof(array)/sizeof(int);

    printf("Rand Array: ");
    PrintArray(array,arraySize);

    InsertionSort(array, arraySize);

    printf("Sorted Array: ");
    PrintArray(array,arraySize);

    return 0;
}
