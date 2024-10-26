#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int ans = -1;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dx2[4][4] = {{0, 1, 1, 1}, {0, 0, 0, 1}, {1, 0, 1, 2}, {0, 1, 2, 1}};
const int dy2[4][4] = {{1, 0, 1, 2}, {0, 1, 2, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}}; // ㅗ 모양
int board[501][501];
bool visited[501][501];

bool isInBoard(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
} // 보드 내에 있는가?

void backtrack(int x, int y, int sum, int stack) {
    for(int i = 0; i < 4; i++) { // 4방향에 대해서
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(!isInBoard(next_x, next_y))
            continue; // 보드 안에 없으면 건너뜀
        if(visited[next_x][next_y])
            continue; // 이미 방문한 곳이면 건너 뜀
        int next_sum = sum + board[next_x][next_y];
        if(stack == 2) { // 이미 3개 연결했으면 이번이 끝
            ans = max(ans, next_sum);
        }
        else { // 아니면 체크후 백트래킹
            visited[next_x][next_y] = true;
            backtrack(next_x, next_y, next_sum, stack + 1);
            visited[next_x][next_y] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;
            backtrack(i, j, board[i][j], 0); // 모든 지점에 대해서 4칸 백트래킹 수행
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) { // 모든 지점에 대해서
            for(int k = 0; k < 4; k++) { // ㅗ 모양
                int sum = 0;
                bool chk = true;
                for(int t = 0; t < 4; t++) {
                    int next_x = i + dx2[k][t];
                    int next_y = j + dy2[k][t];
                    if(!isInBoard(next_x, next_y)) {
                        chk = false;
                        break;
                    } // 하나라도 보드 안에 없으면 안해줌
                    sum += board[next_x][next_y];
                }
                if(chk)
                    ans = max(ans, sum);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}