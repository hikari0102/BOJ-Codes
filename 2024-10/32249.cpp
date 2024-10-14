#include <stdio.h>
#include <memory.h>

/*
https://www.acmicpc.net/problem/32249
처음에 시뮬레이션인줄 알았는데 아니었던 문제
*/

int N, M;
int A_board[10][1000000], B_board[10][1000000]; // A게임판 B게임판

int main() {
    scanf("%d %d", &N, &M);
    int A_BCount = 0, A_BCount_last_line = 0; // A게임판 B개수
    int B_ACount = 0, B_ACount_last_line = 0; // B게임판 A개수
    for(int i = 0; i < N; i++) {
        char str[1000001];
        scanf("%s", str);
        for(int j = 0; j < M; j++) {
            if(str[j] == 'A')
                A_board[i][j] = -1;
            else {
                A_board[i][j] = 1;
                if(i == N - 1)
                    A_BCount_last_line++; // 마지막 줄은 따로 세준다
                else
                    A_BCount++;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        char str[1000001];
        scanf("%s", str);
        for(int j = 0; j < M; j++) {
            if(str[j] == 'A') {
                B_board[i][j] = -1;
                if(i == N - 1)
                    B_ACount_last_line++; // 마지막 줄은 따로 세준다
                else
                    B_ACount++;
            }
            else
                B_board[i][j] = 1;
        }
    }
    int A_score = A_BCount + (A_BCount_last_line - 1);
    if(A_BCount_last_line <= 0)
        A_score++; // 마지막 줄은 먹으면 게임 끝나니까 1개 제외해줌
    int B_score = B_ACount + (B_ACount_last_line - 1);
    if(B_ACount_last_line <= 0)
        B_score++;
    if(A_score <= B_score) // A가 선공이니까 A가 턴 바뀌는 횟수가 B가 턴 바뀌는 횟수보다 적거나 같으면 A가 이김
        printf("Alice\n");
    else
        printf("Bob\n");
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if(A_board[r1 - 1][c1 - 1] == 1) {
            if(r1 - 1 == N - 1) 
                A_BCount_last_line--;
            else
                A_BCount--;
        }
        if(B_board[r2 - 1][c2 - 1] == -1) {
            if(r2 - 1 == N - 1) 
                B_ACount_last_line--;
            else
                B_ACount--;
        }
        int temp;
        temp = A_board[r1 - 1][c1 - 1];
        A_board[r1 - 1][c1 - 1] = B_board[r2 - 1][c2 - 1];
        B_board[r2 - 1][c2 - 1] = temp;
        if(A_board[r1 - 1][c1 - 1] == 1) {
            if(r1 - 1 == N - 1) 
                A_BCount_last_line++;
            else
                A_BCount++;
        }
        if(B_board[r2 - 1][c2 - 1] == -1) {
            if(r2 - 1 == N - 1) 
                B_ACount_last_line++;
            else
                B_ACount++;
        } // 변경따라서 갱신 후
        A_score = A_BCount + (A_BCount_last_line - 1);
        if(A_BCount_last_line <= 0)
            A_score++;
        B_score = B_ACount + (B_ACount_last_line - 1);
        if(B_ACount_last_line <= 0)
            B_score++;
        if(A_score <= B_score) // 아까와 같은 방식으로 턴 바뀌는 횟수 계산 후 승자 판정
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}