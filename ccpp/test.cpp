#include <stdio.h>
#include <math.h>

// Hàm tính MSE
double calculate_mse(double* actual, double* predicted, int n) {
    double mse = 0.0;
    for (int i = 0; i < n; i++) {
        double error = actual[i] - predicted[i];
        mse += error * error;
    }
    return mse / n;
}

int main() {
    // Số lượng lần đo
    int n = 5;
    
    // Giá trị thực tế
    double actual[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    
    // Giá trị dự đoán
    double predicted[] = {1.1, 1.9, 3.2, 4.0, 4.8};
    
    // Tính MSE
    double mse = calculate_mse(actual, predicted, n);
    
    // In kết quả
    printf("Sai số trung bình bình phương (MSE): %f\n", mse);
    
    return 0;
}