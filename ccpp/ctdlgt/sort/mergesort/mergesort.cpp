#include <bits/stdc++.h>
using namespace std;

// Gộp hai mảng con a[l...m] và a[m+1..r],  l=left,m=mid, r=right
void merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;  //lưu trữ kích thước mảng con L (mảng bên trái)
    int n2 = r - m;      //lưu trữ kích thước mảng con R  (mảng bên phải)
    // Tạo các mảng tạm giúp quá trình gộp hiệu quả mà ko ảnh hưởng đến mảng gốc 
    int L[n1], R[n2];
    // Copy dữ liệu sang các mảng tạm
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    // Gộp hai mảng tạm vừa rồi vào mảng a
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy các phần tử còn lại của mảng L vào a nếu có
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    // Copy các phần tử còn lại của mảng R vào a nếu có
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

// l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp
void mergeSort(int a[], int l, int r){    
    if (l < r){
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l + (r - l) / 2;
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Hàm xuất mảng
void printArray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int a[n];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Mang da cho: ";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    cout << "Mang da sap xep: ";
    printArray(a, n);
    return 0;
}
