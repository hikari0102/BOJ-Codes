#include <stdio.h>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/1304
/*
고속도로에 의해서 같은 지역에 속하는 도시들의 번호는 연속이며, 번호가 더 큰 도시에서 더 작은 도시로 가는 것만 신경 쓰면 됨.
1~k, k + 1~2k, ... pk~N 으로 그룹을 나누고 서로 다른 그룹끼리 연결된 간선이 있는가??
*/

int rev_edge[3001][2];
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    int cnt = 0;
    for(int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        if(end < start) {
            rev_edge[cnt][0] = start;
            rev_edge[cnt][1] = end;
            cnt++; // 역방향인 간선만 저장
        }
    }
    for(int i = 1; i <= N; i++) {
        if(N % i != 0)
            continue; // i개의 지역으로 나눌때 
        bool chk = true;
        int q = N / i; // 지역당 도시 개수
        for(int j = 0; j < cnt; j++) {
            if((rev_edge[j][0] - 1) / i != (rev_edge[j][1] - 1) / i) { // 역방향 간선의 시작점이 서로 다른 지역에 있으면??
                chk = false; // 그걸로 못나눔.
                break;
            }
        }
        if(chk) {
            printf("%d\n", q); // 나눌 수 있다면 지역당 도시 개수 출력 후 종료
            break;
        }
    }
    return 0;
}