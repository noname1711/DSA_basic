#include<stdio.h>
#include<math.h>
#include<string.h>

int SNT(int n){
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int TN(int n){
    int m = n;
    int k = 0;
    while(m > 0){
        k = k * 10 + m % 10;
        m = m / 10;
    }
    if (k == n) return 1;
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        int test = 0;
        for (int i = a; i <= b; i++){
            if (test == 10){
                printf("\n"); test = 0;
            }
            if (SNT(i) == 1 && TN(i)){
                printf("%d ", i);
                test++;
            }
        }
        printf("\n");
    }
}
