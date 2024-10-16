#include <stdio.h>

#define M 1000000007 // 나머지

long long int mul(long long int base, long long int exp) {
    if(exp == 0)
        return 1;
    if(exp == 1) 
        return base;
    else if(exp % 2 == 0) {
        long long int half = mul(base, exp / 2);
        return (half * half) % M;
    }
    else
        return (mul(base, exp - 1) * base) % M;
} // 분할정복 거듭제곱 계산 함수 

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    long long int n_fact = 1, k_fact = 1, n_k_fact = 1;
    for(int i = 2; i <= n; i++)
        n_fact = (n_fact * i) % M; // n!
    for(int i = 2; i <= k; i++)
        k_fact = (k_fact * i) % M; // k!
    for(int i = 2; i <= n - k; i++)
        n_k_fact = (n_k_fact * i) % M; // (n-k)!
    long long int B = (k_fact * n_k_fact) % M; 
    long long int temp = mul(B, M - 2); 

    /*
    nCr = n!/(k!*(n-k)!)인데 페르마의 소정리에 의해서 (k!*(n-k)!)^(M-1) mod M = 1 (M은 소수)
    따라서 nCr mod M = n!/(k!*(n-k)!) mod M = n!/(k!*(n-k)!)*(k!*(n-k)!)^(M-1) mod M
    =n!*(k!*(n-k)!)^(M-2) mod M (ab mod M = ((a mod M)*(b mod M)) mod M)
    */
    printf("%lld\n", (n_fact * temp) % M);
    return 0;
}