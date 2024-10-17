#include <stdio.h>

#define MOD 1000000007

// https://www.acmicpc.net/problem/13977

long long int fact[4000001];

long long int mul(long long int base, long long int exp) {
    if(exp == 0)
        return 1;
    if(exp == 1) 
        return base;
    else if(exp % 2 == 0) {
        long long int half = mul(base, exp / 2);
        return (half * half) % MOD;
    }
    else
        return (mul(base, exp - 1) * base) % MOD;
} // 분할 정복 거듭제곱

long long int nCr(int n, int k) {
    long long int n_fact = fact[n], k_fact = fact[k], n_k_fact = fact[n - k];
    long long int B = (k_fact * n_k_fact) % MOD; 
    long long int temp = mul(B, MOD - 2);
    return (n_fact * temp) % MOD;
} // 11401이랑 같은 원리로 계산

int main() {
    fact[0] = 1; // 이거 빼먹어서 틀렸음..
    fact[1] = 1;
    for(int i = 2; i <= 4000000; i++)
        fact[i] = (fact[i - 1] * i) % MOD; // 4000000! 까지 미리 계산(안하면 시간 초과 남)
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%lld\n", nCr(x, y));
    }
    return 0;
}