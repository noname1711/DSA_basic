#include <stdio.h>

long long gt(int n) {
    if (n < 0) {
        return -1; 
    }
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N;
    scanf("%d", &N);

    long long result = gt(N);
    if (result == -1) {
        printf("Error\n");
    } else {
        printf("%d", result);
    }
    
    return 0;
}
