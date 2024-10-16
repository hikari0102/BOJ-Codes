#include <stdio.h>

// https://www.acmicpc.net/problem/14565

int main() {
    long long int a, n;
    scanf("%lld %lld", &n, &a);
    long long int r = a, s = 0, t = 1;
    long long int prev_r = n, prev_s = 1, prev_t = 0;
    while(r > 0) {
        long long int temp;
        long long int q = prev_r / r;
        temp = prev_r;
        prev_r = r;
        r = temp - q * r;
        temp = prev_s;
        prev_s = s;
        s = temp - q * s;
        temp = prev_t;
        prev_t = t;
        t = temp - q * t;
    } // n * prev_s + a * prev_t = prev_r 
    // 확장 유클리드 알고리즘
    long long int mul_inv = prev_t;
    if(mul_inv >= n) {
        while(mul_inv >= n)
            mul_inv -= n;
    }
    else if(mul_inv < 0) {
        while(mul_inv < 0)
            mul_inv += n;
    } // 역원 1~n 사이 값으로 조정
    if(prev_r != 1) // n, a 서로소 아니면 역원 없음.
        printf("%lld -1\n", n - a);
    else
        printf("%lld %lld\n", n - a, mul_inv);
    return 0;
}