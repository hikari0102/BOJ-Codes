#include <stdio.h>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/31264

int N, M, A, s[100001];

int main() {
    scanf("%d %d %d", &N, &M, &A);
    for(int i = 0; i < N; i++)
        scanf("%d", &s[i]);
    sort(s, s + N); // 정렬
    long left = s[0], right = s[N - 1]; // 초기 범위 설정(right = 10^10으로 설정 했었는데 안해도 됨)
    long ret = 1e11;
    while(left <= right) {
        long mid = (left + right) / 2;
        long current_ability = mid; // 초기 사격 실력
        long current_score = 0; // 점수
        for(int i = 0; i < M; i++) {
            long target_index = lower_bound(s, s + N, current_ability) - s; // 사격 실력보다 같거나 큰 원소중 제일 앞에 있는거 위치
            if(target_index >= N) { // 다 맞출 수 있으면
                current_ability += s[N - 1];
                current_score += s[N - 1]; // 제일 점수 높은거 맞춤
                continue;
            }
            if(s[target_index] <= current_ability) { // 아까 사격실력이랑 같은거 나왔으면
                current_ability += s[target_index];
                current_score += s[target_index]; // 같은거 맞춤
            }
            else { // 아까 더 큰거 나왔으면 
                current_ability += s[target_index - 1];
                current_score += s[target_index - 1]; // 그 전꺼 맞춤
            }
        }
        if(current_score >= A) { // 점수 진급 가능이면
            right = mid - 1; // 답은 더 작음
            ret = min(ret, mid);
        }
        else // 아니면
            left = mid + 1; // 답이 더 큼
    }
    printf("%ld\n", ret);
    return 0;
}