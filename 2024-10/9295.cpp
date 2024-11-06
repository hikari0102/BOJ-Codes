#include <stdio.h>

// https://www.acmicpc.net/problem/9295
/*
#구현
스트릭 유지할려고 풀은 문제라 별게 없다?
*/

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("Case %d: %d\n", i, x + y);
    }
    return 0;
}