#include <iostream>
#include <chrono>


using namespace std;

void printSequence(char prefix) {
    for (int i = 1; i <= 10; i++) {
        cout << prefix << ": " << i << endl;
        //this_thread::sleep_for(chrono::seconds(1));  //trễ 1 giây
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    printSequence('A');
    printSequence('B');
    printSequence('C');

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    cout << "Thoi gian thuc thi: " << elapsed.count() << " s" << endl;
    return 0;
}
