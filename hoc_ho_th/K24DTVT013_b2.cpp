#include <stdio.h>

void chenGiaTriTangDan(int arr[], int *size, int x) {
    int i;
    for (i = *size - 1; i >= 0 && arr[i] > x; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = x;
    (*size)++;
}

void inMang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size;
    int x;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &size);

    printf("Nhap cac phan tu cua mang tang dan: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri x can chen: ");
    scanf("%d", &x);

    chenGiaTriTangDan(arr, &size, x);

    printf("Mang sau khi chen x: ");
    inMang(arr, size);

    return 0;
}
