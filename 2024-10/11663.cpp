#include <stdio.h>
#include <algorithm>


// https://www.acmicpc.net/problem/11663
/*
#이분탐색, #정렬
정렬한 뒤 이분탐색으로 점의 시작점과 점의 끝점의 인덱스를 파악한후 인덱스로 사이의 점의 개수를 구해주면 된다.
이때 완전히 일치하지 않는 경우 인덱스를 보정해줘야함. (이거 안해서 틀림)
*/
int N, M;
int dots[100000];

int binary_search(int x) {
    int left = 0, right = N - 1, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(dots[mid] == x)
            break;
        else if(dots[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return mid;
} // 이분 탐색

int main() {
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &dots[i]);
    std::sort(dots, dots + N); // 정렬
    for(int i = 0; i < M; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        int left_idx = binary_search(s);
        int right_idx = binary_search(e); // 이분탐색
        if(dots[right_idx] > e) // 선분 끝점 인덱스 보정
            right_idx--;
        if(dots[left_idx] < s) // 선분 시작점 인덱스 보정
            left_idx++;
        int ans = std::abs(right_idx - left_idx + 1); // 인덱스로 답 계산
        printf("%d\n", ans);
    }
    return 0;
}