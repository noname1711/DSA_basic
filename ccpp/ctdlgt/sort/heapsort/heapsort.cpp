#include <bits/stdc++.h>
using namespace std;

// Hàm để hiệu chỉnh một cây con với gốc là n và là một cây max heap
void heapify(int a[], int n, int i) {
    int max = i;  // Khởi tạo max là gốc 
    int l = 2 * i + 1;  // Chỉ số của nút con bên trái (luôn là số lẻ)
    int r = 2 * i + 2;  // Chỉ số của nút con bên phải (luôn là số chẵn)
    // So sánh nút gốc với nút con bên trái
    if (l < n && a[l] > a[max])  //đảm bảo l còn trong mảng và nếu a[l]> gốc thì gán a[l] là gốc
        max = l;
    // So sánh nút gốc (hoặc max sau bước trước) với nút con bên phải
    if (r < n && a[r] > a[max])  //tương tự như l
        max = r;
    // Nếu max không phải là gốc, hoán đổi và tiếp tục heapify cây con bị ảnh hưởng
    if (max != i) {  //tồn tại ít nhất 1 nút con có giá trị lớn hơn nút i hiện tại thì đảo và tiếp tục làm lại cây
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}

// Hàm swap để hoán đổi giá trị của hai biến
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Hàm thực hiện Heap Sort
void heapSort(int a[], int n) {
    // Xây dựng max heap
    for (int i = n / 2 - 1; i >= 0; i--)  //duyệt từ cuối mảng lên đầu mảng
        heapify(a, n, i);  //hiệu chỉnh cây từ nút i và đảm bảo nút cha luôn là max 
    // Trích xuất lần lượt phần tử lớn nhất từ heap và đặt ở cuối mảng
    for (int i = n - 1; i > 0; i--) {  //duyệt lại sau khi loại bỏ phần tử max ở cuối mảng
        swap(a[0], a[i]);  // Di chuyển gốc (phần tử lớn nhất) đến cuối mảng
        heapify(a, i, 0);  // Gọi heapify để giảm kích thước heap và đảm bảo tính chất heap
    }
}

int main() {
    int n;
    cin>>n; int a[n];
    for(int i=0;i< n;i++){
        cin >> a[i];
    }
    heapSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

