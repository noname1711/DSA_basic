#include <stdio.h>

void rotateLeft(int arr[], int n, int d) {
    int temp[d];
    

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    

    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d];
    }
    

    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

int main() {
    int n, d;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &d);
    rotateLeft(arr, n, d);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
