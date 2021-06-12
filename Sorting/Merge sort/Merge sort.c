#include <stdio.h>
#include <stdlib.h>

void Merge(int* array, const int begin, const int middle, const int end){
    int i, j, k;
    int* tempArray = (int*)malloc((end - begin+1)*sizeof(int));

    i = begin;
    j = middle + 1;
    k = begin;

    while(i <= middle && j <= end){
        if(array[i] < array[j]){
            tempArray[k] = array[i];
            i++;
        }
        else{
            tempArray[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= middle){
        tempArray[k] = array[i];
        i++;
        k++;
    }

    while(j <= end){
        tempArray[k] = array[j];
        j++;
        k++;
    }

    for(int aux = begin; aux <= end; aux++)
        array[aux] = tempArray[aux];
}

void MergeSort(const int* array, const int begin, const int end){
    if(begin < end){
        int middle = (end+begin)/2;

        MergeSort(array, begin, middle);
        MergeSort(array, middle+1, end);
        Merge(array, begin, middle, end);
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

    MergeSort(array, 0, arraySize);

    printf("Sorted Array: ");
    PrintArray(array,arraySize);

    return 0;
}
