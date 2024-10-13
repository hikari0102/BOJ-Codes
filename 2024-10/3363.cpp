#include <stdio.h>

// https://www.acmicpc.net/problem/3363

int main() {
    int cond[3][9]; // 0 ~ 3 => 왼쪽, 4 ~ 7 => 오른쪽, 8 => 가운데 부등호 (1 : >, 0 : =, -1 : <)
    for(int i = 0; i < 3; i++) {
        char c[2];
        for(int j = 0; j < 4; j++)
            scanf("%d", &cond[i][j]);
        scanf("%s", c);
        if(c[0] == '>')
            cond[i][8] = 1;
        else if(c[0]  == '<')
            cond[i][8] = -1;
        else
            cond[i][8] = 0;
        for(int j = 4; j < 8; j++)
            scanf("%d", &cond[i][j]);
    } // 입력
    int ans[25][2], cnt = 0; // 정답인 것들 저장할 배열 및 정답 개수
    for(int i = 1; i <= 12; i++) { // 구슬 번호
        for(int j = 0; j < 2; j++) { // 가벼우면 0 무거우면 1
            int chk = 0; // 만족하는 조건의 개수
            for(int k = 0; k < 3; k++) {
                int left_sum = 0, right_sum = 0;
                for(int l = 0; l < 4; l++) {
                    if(cond[k][l] != i)
                        left_sum += 2;
                    else {
                        if(j == 0)
                            left_sum += 1;
                        else
                            left_sum += 3;
                    }
                } // 부등호 좌변 계산 (무거우면 3, 일반은 2, 가벼우면 1로 계산)
                for(int l = 4; l < 8; l++) {
                    if(cond[k][l] != i)
                        right_sum += 2;
                    else {
                        if(j == 0)
                            right_sum += 1;
                        else
                            right_sum += 3;
                    }
                } // 부등호 우변 계산 (무거우면 3, 일반은 2, 가벼우면 1로 계산)
                if((cond[k][8] == -1 && left_sum < right_sum) || (cond[k][8] == 0 && left_sum == right_sum) 
                || (cond[k][8] == 1 && left_sum > right_sum)) // 조건에 맞는지 체크
                    chk++;
            }
            if(chk == 3) { // 3개 다 일치하면 정답에 저장
                ans[cnt][0] = i;
                ans[cnt][1] = j;
                cnt++;
            }
        }
    }
    if(cnt == 1) { // 정답개수 1개면 출력
        if(ans[0][1] == 0)
            printf("%d-\n", ans[0][0]);
        else
            printf("%d+\n", ans[0][0]);
    }
    else if(cnt == 0) // 정답 없으면 impossible
        printf("impossible\n");
    else // 정답 여러개면 indefinite
        printf("indefinite\n");
}