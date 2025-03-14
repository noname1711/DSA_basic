#include<bits/stdc++.h>
using namespace std;

// Hàm hoán đổi giá trị của hai biến
void _swap(int &a, int &b) {
    int x = a;
    a = b;
    b = x;
}

int main() {
    int n; 
    cin >> n;
    int a[n];

    // Nhập mảng từ người dùng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bắt đầu thuật toán sắp xếp Bubble Sort
    for (int i = 0; i < n - 1; i++) {  // xét đến phần tử liền cuối bởi cứ mỗi vòng lặp phần tử max sẽ xuống cuối dòng
        bool check_swap = true;   //tạo biến check_swap 
        // nếu check_swap =true thì ko cần đổi vị trí a[i] và a[i+1], false thì ngược lại
        // Duyệt qua từng phần tử của mảng
        for (int j = 0; j < n - i - 1; j++) { // do mỗi vòng lặp i < n-1 thì đã đẩy max về cuối nên để tối ưu, ta sẽ ko xét các phần tử ở cuối nữa
            // Nếu phần tử hiện tại lớn hơn phần tử kế tiếp, hoán đổi chúng
            if (a[j] > a[j + 1]) {
                check_swap = false;
                _swap(a[j], a[j + 1]);
            }
        }

        // Nếu không có sự hoán đổi nào được thực hiện(check_swap là true), dãy đã được sắp xếp, thoát khỏi vòng lặp
        if (check_swap == true) break;
    }

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

