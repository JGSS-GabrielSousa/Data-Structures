#include <stdio.h>
#include <stdlib.h>

void Merge(int* array, int begin, int middle, int end){
    int i, j, k;
    int n1 = middle - begin + 1;
    int n2 = end - middle;
    int leftTempArray[n1];
    int rightTempArray[n2];

    for(i = 0; i < n1; i++)
        leftTempArray[i] = array[begin + i];
    for(j = 0; j < n2; j++)
        rightTempArray[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = begin;

    while(i < n1 && j < n2){
        if(leftTempArray[i] <= rightTempArray[j]){
            array[k] = leftTempArray[i];
            i++;
        }
        else{
            array[k] = rightTempArray[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        array[k] = leftTempArray[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = rightTempArray[j];
        j++;
        k++;
    }
}

void MergeSort(int* array, int begin, int end){
    if(begin < end){
        int middle = begin + (end - begin) / 2;

        MergeSort(array, begin, middle);
        MergeSort(array, middle + 1, end);

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
    int arraySize = sizeof(array) / sizeof(int);

    printf("Rand Array: ");
    PrintArray(array, arraySize);

    MergeSort(array, 0, arraySize - 1);

    printf("Sorted Array: ");
    PrintArray(array, arraySize);

    return 0;
}
