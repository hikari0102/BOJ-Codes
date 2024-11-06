#include <stdio.h>

#define MOD 10007

// https://www.acmicpc.net/problem/1437
/*
#dp
수학적으로 증명은 몰?루겠는데 4의 경우를 제외하면 3을 많이 만들면 곱이 컸다.
따라서 dp[N] = dp[N - 3] * 3
*/

int main() {
    int N;
    int dp[5] = {0, 1, 2, 3, 4};
    scanf("%d", &N);
    if(N < 5)
        printf("%d\n", dp[N]);
    else {
        for(int i = 5; i <= N; i++) {
            for(int j = 1; j < 4; j++)
                dp[j] = dp[j + 1];
            dp[4] = (dp[1] * 3) % MOD;
        }
        printf("%d\n", dp[4]);
    }
    return 0;
}