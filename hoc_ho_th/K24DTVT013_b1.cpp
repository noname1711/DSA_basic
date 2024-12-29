#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "input.txt"

void docFile(int arr[], int *size) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        exit(1);
    }

    fscanf(file, "%d", size);
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void inMang(int arr[], int size) {
    printf("So phan tu: %d\n", size);
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int timViTriMin(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void chenGiaTri(int arr[], int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void xoaGiaTri(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100];
    int size;
    int choice;

    docFile(arr, &size);

    do {
        printf("\n1. Doc file input va in ket qua ra man hinh\n");
        printf("2. Tim gia tri nho nhat (hoac vi tri gia tri nho nhat)\n");
        printf("3. Chen gia tri vao vi tri k\n");
        printf("4. Xoa gia tri tai vi tri k\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inMang(arr, size);
                break;
            case 2: {
                int minIndex = timViTriMin(arr, size);
                printf("Gia tri nho nhat la %d tai vi tri %d\n", arr[minIndex], minIndex);
                break;
            }
            case 3: {
                int k, x;
                printf("Nhap vi tri k: ");
                scanf("%d", &k);
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                chenGiaTri(arr, &size, k, x);
                printf("Mang sau khi chen: \n");
                inMang(arr, size);
                break;
            }
            case 4: {
                int k;
                printf("Nhap vi tri k: ");
                scanf("%d", &k);
                xoaGiaTri(arr, &size, k);
                printf("Mang sau khi xoa: \n");
                inMang(arr, size);
                break;
            }
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}
