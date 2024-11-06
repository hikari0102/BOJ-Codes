#include <stdio.h>

// https://www.acmicpc.net/problem/11561
/*
#이분탐색, #그리디
맨 처음에 1만큼 점프를 뛰고, 그다음은 2, 3, 4, ... 로 점프를 뛰어야 가장 많은 돌을 밟고 간다.
따라서 이분탐색을 활용하여 1 + 2 + 3 + ... + k = k(k + 1) / 2 <= N인 k 중 가장 큰 값을 찾으면 된다.
*/

unsigned long long int sum(unsigned long long int x) {
    return x * (x + 1) / 2;
} // k(k + 1) / 2

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        unsigned long long int N;
        scanf("%llu", &N);
        unsigned long long int left = 0, right = N, mid;
        unsigned long long int ans = -1;
        while(left <= right) { // 이분 탐색
            mid = (left + right) / 2;
            if(sum(mid) <= N) {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        printf("%lld\n", ans);
    }
}