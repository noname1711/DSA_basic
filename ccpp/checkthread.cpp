#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printSequence(char prefix) {
    for (int i = 1; i <= 10; i++) {
        cout << prefix << ": " << i << endl;
        //this_thread::sleep_for(chrono::seconds(1));  //trễ thêm 1s giữa các lần in 
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    // Tạo luồng
    thread t1(printSequence, 'A');
    thread t2(printSequence, 'B');
    thread t3(printSequence, 'C');

    // Chờ các luồng kết thúc
    t1.join();
    t2.join();
    t3.join();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    cout << "Thoi gian thuc thi: " << elapsed.count() << " s" << endl;
    return 0;
}
