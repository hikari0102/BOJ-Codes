#include <stdio.h>

// https://www.acmicpc.net/problem/4574
/*
#구현 #백트래킹
2580 스도쿠 문제 강화버전이다. 백트래킹으로 모든 빈 공간에 도미노를 놓으면서 전부 채우면 출력하면 된다.
*/

bool used_doniminos[10][10]; // 사용된 도미노
bool row_chk[10][10]; // 행 체크 i번 행에 j가 있으면 [i][j] = true
bool col_chk[10][10]; // 열 체크
bool box_chk[10][10]; // 상자 체크
int board[10][10]; // 현재 보드 상태
int zero_cnt; // 빈칸 개수
int zero_idx[81][2]; // 빈칸의 인덱스
int puzzle_num; // 퍼즐 번호 출력용
const int dx[4] = {1, 0, -1, 0}; // 도미노 4방향
const int dy[4] = {0, 1, 0, -1};
bool cleared = false; // 이미 풀었는가? 풀었으면 백트래킹 그만하는 용도

int getBoxIndex(int row, int col) {
    return (row / 3) * 3 + (col / 3); // 상자 번호 반환
}

bool isInBoard(int row, int col) {
    return (row >= 0) && (row < 9) && (col >= 0) && (col < 9); // 보드 안에 있는가?
}

bool isUnable(int row, int col, int num) {
    int box = getBoxIndex(row, col);
    return row_chk[row][num] || col_chk[col][num] || box_chk[box][num]; // 행, 열, 상자를 고려 했을때 둘 수 있는가?
}

void setBoard(int row, int col, int num) { // row열, col행에 num이라는 숫자를 배치
    int box = getBoxIndex(row, col);
    row_chk[row][num] = true;
    col_chk[col][num] = true;
    box_chk[box][num] = true;
    board[row][col] = num;
}

void unBoard(int row, int col) { // row열, col행을 다시 빈칸으로
    int box = getBoxIndex(row, col);
    int num = board[row][col];
    row_chk[row][num] = false;
    col_chk[col][num] = false;
    box_chk[box][num] = false;
    board[row][col] = 0;
}

void backtrack(int p) { // p는 현재까지 채운 빈칸의 개수
    if(cleared) // 이미 클리어 한 경우 종료
        return;
    if(p == zero_cnt) { // 빈칸 전부 채웠으면
        printf("Puzzle %d\n", puzzle_num);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++)
                printf("%d", board[i][j]);
            printf("\n");
        } // 출력
        cleared = true; // 클리어 했다고 표시
        return; // 종료
    }
    int current_row = zero_idx[p][0];
    int current_col = zero_idx[p][1]; // 현재 채울 칸의 행 및 열 번호
    if(board[current_row][current_col] != 0) // 도미노 등으로 이미 채워진 경우
        backtrack(p + 1); // 다음 빈칸으로 이동
    else {
        for(int i = 1; i <= 9; i++) {
            if(isUnable(current_row, current_col, i)) // i를 둘 수 없다면 다음 숫자 확인
                continue;
            setBoard(current_row, current_col, i); // i를 둔 다음
            for(int j = 1; j <= 9; j++) { 
                if(used_doniminos[i][j] || used_doniminos[j][i] || i == j) // 도미노 확인
                    continue;
                for(int k = 0; k < 4; k++) { // 도미노 4방향 확인
                    int next_row = current_row + dx[k];
                    int next_col = current_col + dy[k];
                    if(!isInBoard(next_row, next_col)) // 보드를 나가면 다른 방향 확인
                        continue;
                    if(isUnable(next_row, next_col, j)) // 해당 칸에 도미노의 다른 숫자를 둘 수 없다면 다른 방향 확인
                        continue;
                    if(board[next_row][next_col] != 0) // 이미 숫자가 채워져 있으면 다른 방향 확인
                        continue;
                    setBoard(next_row, next_col, j); // 도미노 배치후
                    used_doniminos[i][j] = true;
                    used_doniminos[j][i] = true; // 도미노 사용했다고 표시
                    backtrack(p + 1); // 다음 빈칸으로
                    unBoard(next_row, next_col); // 도미노 해제
                    used_doniminos[i][j] = false;
                    used_doniminos[j][i] = false; // 도미노 사용 가능 하다고 표시
                }
            }
            unBoard(current_row, current_col); // i도 해제
        }
    }
}

int main() {
    while(true) {
        puzzle_num++;
        int N;
        scanf("%d", &N);
        if(N == 0)
            break; // N = 0이면 종료
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                used_doniminos[i][j] = false;
                row_chk[i][j] = false;
                col_chk[i][j] = false;
                box_chk[i][j] = false;
                board[i][j] = 0;
            }
        } // 초기화
        for(int i = 0; i < N; i++) {
            zero_cnt = 0;
            cleared = false;
            char pos_1[3] = "", pos_2[3] = "";
            int num_1, num_2;
            scanf("%d %s %d %s", &num_1, pos_1, &num_2, pos_2);
            int row_idx_1 = pos_1[0] - 'A';
            int row_idx_2 = pos_2[0] - 'A';
            int col_idx_1 = pos_1[1] - '1';
            int col_idx_2 = pos_2[1] - '1'; // 알파벳 숫자 꼴 번호로 변경
            setBoard(row_idx_1, col_idx_1, num_1);
            setBoard(row_idx_2, col_idx_2, num_2); // 도미노 배치
            used_doniminos[num_2][num_1] = true;
            used_doniminos[num_1][num_2] = true; // 도미노 사용 불가라고 표시
        }
        for(int i = 1; i <= 9; i++) {
            char pos[3] = "";
            scanf("%s", pos);
            int row_idx = pos[0] - 'A';
            int col_idx = pos[1] - '1'; // 알파벳 숫자 꼴 번호로 변경
            setBoard(row_idx, col_idx, i); // 숫자 배치
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == 0) {
                    zero_idx[zero_cnt][0] = i;
                    zero_idx[zero_cnt][1] = j;
                    zero_cnt++; // 빈칸들 정보 저장 후
                }
            }
        }
        backtrack(0); // 백트래킹
    }
    return 0;
}