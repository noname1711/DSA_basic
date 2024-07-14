#include <bits/stdc++.h>
using namespace std;
int main() {
    // Khai báo queue và mảng
    queue<string> myQueue;
    int n;
    // Nhập số lần lặp từ bàn phím
    cout << "Nhap so lan lap: ";
    cin >> n;
    // Nhập dãy string ban đầu
    cout << "Nhap day string ban dau: ";
    string initialString;
    cin >> initialString;
    // Thêm initialString vào queue
    myQueue.push(initialString);
    // Thực hiện lặp n lần
    for (int i = 0; i < n; i++) {
        // Lấy phần tử đầu tiên ra khỏi queue
        string frontElement = myQueue.front();
        myQueue.pop();
        // Lấy kí tự bị xóa
        char removedChar = frontElement[0];
        // Xóa phần tử ở đầu và thêm vào cuối kí tự vừa xóa
        frontElement.erase(frontElement.begin());
        frontElement += removedChar;
        // In ra dãy mới
        cout << "Dai sau lan lap " << i + 1 << ": " << frontElement << endl;
        // Thêm dãy mới vào cuối queue
        myQueue.push(frontElement);
    }
    return 0;
}

