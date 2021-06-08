#include <stdio.h>

void Swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(const int* array, const int low, const int high){
    int pivot = array[high];
    int i = (low - 1);

    for(int j = low; j <= high-1; j++){
        if(array[j] <= pivot){
            i++;
            Swap(&array[i], &array[j]);
        }
    }

    Swap(&array[i+1], &array[high]);
    return(i+1);
}

void Quicksort(const int* array, const int low, const int high){
    if(low < high){
        int pivot = Partition(array, low, high);
        Quicksort(array, low, pivot - 1);
        Quicksort(array, pivot + 1, high);
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

    Quicksort(array, 0, arraySize-1);

    printf("Sorted Array: ");
    PrintArray(array,arraySize);

    return 0;
}
