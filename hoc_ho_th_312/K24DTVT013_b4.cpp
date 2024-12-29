#include <stdio.h>

#define MAX_N 100000

int main() {
    int T; 
    scanf("%d", &T);

    while (T--) {
        int N, A[MAX_N], freq[MAX_N], firstIndex[MAX_N];
        scanf("%d", &N);

       
        for (int i = 0; i < MAX_N; i++) {
            freq[i] = 0;
            firstIndex[i] = -1; 
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            int num = A[i];
            freq[num]++;
            if (firstIndex[num] == -1) {
                firstIndex[num] = i; 
            }
        }

        int minIndex = MAX_N;
        int result = -1;
        for (int i = 0; i < N; i++) {
            int num = A[i];
            if (freq[num] > 1 && firstIndex[num] < minIndex) {
                minIndex = firstIndex[num];
                result = num;
            }
        }

        if (result == -1) {
            printf("NO\n");
        } else {
            printf("%d\n", result);
        }
    }

    return 0;
}
