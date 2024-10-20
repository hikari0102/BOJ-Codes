#include <stdio.h>
#include <algorithm>

using namespace std;

//https://www.acmicpc.net/problem/30644

/*
좌표 압축 후 계속 1씩 감소하거나 증가하는 구간이면 안 나눠도 됨.
*/

int main() {
    int N;
    int a[200001];
    int sorted[200001];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i];
    }
    sort(sorted, sorted + N); // 정렬
    int mode = 0; // 현재 1씩 증가(1), 1씩 감소(-1), 불연속(0)
    int cut = 0;
    int prev, now; // 이전 값 좌표 압축한 값, 현재값 좌표 압축한 값
    for(int i = 0; i < N; i++) {
        prev = now;
        now = lower_bound(sorted, sorted + N, a[i]) - sorted; // 좌표 압축
        if(i == 0) // 첫번째는 이전 값이랑 비교 안되니까 건너뜀
            continue;
        if(mode == 0) { // 불연속이었는데
            if(prev == now + 1) // 이전 값보다 1 작으면
                mode = -1; // 1씩 감소 모드로 전환
            else if(prev == now - 1) // 이전 값보다 1크면
                mode = 1; // 1씩 증가 모드로 전환
            else // 계속 불연속이면
                cut++; // 자르기
        }
        else if(mode == 1) { // 1씩 증가모드인데
            if(prev != now - 1) { // 1씩 증가가 깨졌으면
                mode = 0; // 불연속으로 전환후
                cut++; // 자르기
            }
        }
        else if(mode == -1) { // 1씩 감소모드인데
            if(prev != now + 1) { // 1씩 감소가 깨졌으면
                mode = 0; // 불연속으로 전환후
                cut++; // 자르기
            }
        }
    }
    printf("%d\n", cut);
    return 0;
}