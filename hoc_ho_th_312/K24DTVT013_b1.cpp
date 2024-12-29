#include <stdio.h>

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int max_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        float temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(float arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        float key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j+1] = arr[j]; j = j - 1; 
        } 
        arr[j+1] = key; 
    } 
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float arrBubble[n], arrSelection[n], arrInsertion[n];
    for (int i = 0; i < n; i++) {
        arrBubble[i] = arr[i];
        arrSelection[i] = arr[i];
        arrInsertion[i] = arr[i];
    }

    printf("Sap xep noi bot:\n");
    bubbleSort(arrBubble, n);
    printArray(arrBubble, n);

    printf("Sap xep chon:\n");
    selectionSort(arrSelection, n);
    printArray(arrSelection, n);

    printf("Sap xep chen:\n");
    insertionSort(arrInsertion, n);
    printArray(arrInsertion, n);

    return 0;
}
