#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex print_mutex;  // Tạo một mutex để bảo vệ cout

void printSequence(char prefix) {
    for (int i = 1; i <= 10; i++) {
        //this_thread::sleep_for(chrono::seconds(1));  // Giả lập công việc tốn thời gian
        lock_guard<mutex> lock(print_mutex);  // Đảm bảo chỉ một luồng in ra tại một thời điểm
        cout << prefix << ": " << i << endl;
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    thread t1(printSequence, 'A');
    thread t2(printSequence, 'B');
    thread t3(printSequence, 'C');

    t1.join();
    t2.join();
    t3.join();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    cout << "Thoi gian thuc thi: " << elapsed.count() << " s" << endl;
    return 0;
}
