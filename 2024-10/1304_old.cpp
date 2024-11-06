#include <stdio.h>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/1304
/*
고속도로에 의해서 같은 지역에 속하는 도시들의 번호는 연속이며, 번호가 더 큰 도시에서 더 작은 도시로 가는 것만 신경 쓰면 됨.
1~k, k + 1~2k, ... pk~N 으로 그룹을 나누고 서로 다른 그룹끼리 연결된 간선이 있는가??

알고리즘의 아이디어는 같으나 간선이 아니라 정점을 기준으로 탐색하여 시간이 오래 걸렸음
*/


int graph[3001][3001];
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        if(end < start) {
            for(int j = end; j < start; j++)
                graph[start][j] = 1;
        }
    }
    for(int i = 1; i <= N; i++) {
        bool chk = true;
        if(N % i == 0) {
            for(int j = 1; j <= N; j++) {
                int q = (j - 1) / i;
                int left = q * i + 1; // 그룹의 왼쪽 끝
                int right = (q + 1) * i; // 그룹의 오른쪽 끝
                for(int k = 1; k < left; k++) {
                    if(graph[k][j] == 1) { // 그룹보다 작은 번호의 도시에 연결 선이 있는가?
                        chk = false;
                        break;
                    }
                }
                for(int k = right + 1; k <= N; k++) { // 그룹보다 큰 번호의 도시에 연결 선이 있는가?
                    if(graph[k][j] == 1) {
                        chk = false;
                        break;
                    }
                }
            }
            if(chk) {
                printf("%d\n", N / i);
                break;
            }
        }
        
    }
    return 0;
}