#include <stdio.h>
#include <stdlib.h> // Thu vien cho cac ham xu ly bo nho dong

int main() {
    // Cap phat bo nho bang malloc
    int *arr1 = (int *)malloc(5 * sizeof(int)); // Cap phat vung nho du chua 5 so nguyen
    if (arr1 == NULL) { // Kiem tra cap phat co thanh cong khong
        printf("Khong the cap phat bo nho bang malloc!\n");
        return 1; // Thoat chuong trinh neu cap phat that bai
    }
    printf("Bo nho duoc cap phat bang malloc:\n");
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1; // Gan gia tri tu 1 den 5
        printf("%d ", arr1[i]); // In gia tri tung phan tu
    }
    printf("\n");

    // Cap phat bo nho bang calloc
    int *arr2 = (int *)calloc(5, sizeof(int)); // Cap phat vung nho du chua 5 so nguyen va khoi tao tat ca gia tri = 0
    if (arr2 == NULL) { // Kiem tra cap phat co thanh cong khong
        printf("Khong the cap phat bo nho bang calloc!\n");
        free(arr1); // Giai phong bo nho cua arr1 truoc khi thoat
        return 1; // Thoat chuong trinh neu cap phat that bai
    }
    printf("Bo nho duoc cap phat bang calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]); // In gia tri tung phan tu, mac dinh se la 0
    }
    printf("\n");

    // Thay doi kich thuoc bo nho bang realloc
    arr1 = (int *)realloc(arr1, 10 * sizeof(int)); // Mo rong vung nho tu 5 phan tu len 10 phan tu
    if (arr1 == NULL) { // Kiem tra cap phat lai co thanh cong khong
        printf("Khong the thay doi kich thuoc bo nho bang realloc!\n");
        free(arr2); // Giai phong arr2 truoc khi thoat
        return 1; // Thoat chuong trinh neu cap phat that bai
    }
    printf("Bo nho sau khi su dung realloc (mo rong arr1 len 10 phan tu):\n");
    for (int i = 0; i < 10; i++) {
        if (i >= 5) arr1[i] = i + 1; // Gan gia tri moi cho cac phan tu tu vi tri 5 den 9
        printf("%d ", arr1[i]); // In gia tri tung phan tu
    }
    printf("\n");

    // Giai phong bo nho da cap phat
    free(arr1); // Giai phong vung nho cua arr1
    free(arr2); // Giai phong vung nho cua arr2

    printf("Bo nho da duoc giai phong.\n"); // Xac nhan da giai phong bo nho

    return 0; // Ket thuc chuong trinh
}
