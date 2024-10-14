#include <stdio.h>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/32177

int N, K, T;
int pos[3001][3001]; // 위치
int V[3001]; // 에어드랍 버전
int P[3001]; // 사진 찍었는지?
int graph[3001][3001]; // 모델링된 그래프
int visited[3001]; // 0번 정점(푸앙이)와 연결되어 있는가?


int abs(int x) {
    if(x < 0)
        return -x;
    return x;
}

bool is_connected(int x1, int y1, int x2, int y2) { // 거리가 K 이하인가?
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= K * K;
}

int main() {
    scanf("%d %d %d", &N, &K, &T);
    scanf("%d %d %d", &pos[0][0], &pos[0][1], &V[0]);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d %d %d", &pos[i][0], &pos[i][1], &V[i], &P[i]);
        for(int j = 0; j < i; j++) { // 그래프 모델링
             if(is_connected(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) && abs(V[i] - V[j]) <= T) 
             // 거리 K 이하이고 버전 차이 T이하인가??
                graph[i][j] = graph[j][i] = 1;
        }
    } 
    // 원래 그래프 모델링 입력 다 받고 이중 for 돌려서 했는데 입력 받으면서 해도 처리 됨.
    queue<int> que;
    que.push(0);
    visited[0] = 1; // BFS 수행 전초 작업
    while(!que.empty()) {
        int current_position = que.front(); // 현재 위치
        que.pop();
        for(int i = 0; i <= N; i++) {
            if(graph[current_position][i] == 1 && visited[i] == 0) { // 연결되어 있고 아직 방문 안했으면
                visited[i] = 1; // 방문 한걸로 표시하고
                que.push(i); // 다음 방문지 큐에 삽입
            }
        }
    }
    int is_no = 1;
    for(int i = 1; i <= N; i++) {
        if(visited[i] == 1 && P[i] == 1) { // 0번 정점과 연결되어 있고 사진을 찍었다면
            printf("%d ", i);
            is_no = 0;
        }
    }
    if(is_no == 1) // 사진 찍은 사람중 전달할 사람 없으면
        printf("0");
    printf("\n");
    return 0;
}