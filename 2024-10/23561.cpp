#include <stdio.h>
#include <algorithm>

using namespace std;

/*
https://www.acmicpc.net/problem/23561
#그리디 #정렬
말 그대로 정렬한 다음 가운데의 N개를 모두 크루에서 2번째로 연령이 높도록 설정하면 된다.
*/

int main() {
    int N;
    int arr[300001] = {0};
    scanf("%d", &N);
    for(int i = 0; i < 3 * N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + 3 * N); // 정렬
    printf("%d\n", arr[2 * N - 1] - arr[N]); // 가운데 N개중 가장 큰 것과 가장 작은것의 차이
    return 0;
}