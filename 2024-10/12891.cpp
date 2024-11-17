#include <stdio.h>

// https://www.acmicpc.net/problem/12891
/*
#문자열, #슬라이딩 윈도우
슬라이딩 윈도우를 통해서 길이가 P인 부분 문자열중에서 조건을 만족하는 개수를 구하기
*/

int getIndex(char s) {
    if(s == 'A')
        return 0;
    else if(s == 'C')
        return 1;
    else if(s == 'G')
        return 2;
    else
        return 3;
} // DNA 알파벳별 번호 반환

int main() {
    int S, P;
    char str[1000001];
    int bound[4] = {0}, count[4] = {0};
    int ans = 0;
    scanf("%d %d", &S, &P);
    scanf("%s", str);
    for(int i = 0; i < 4; i++)
        scanf("%d", &bound[i]);
    for(int i = 0; i < P; i++)
        count[getIndex(str[i])]++; // 초기 셋업
    int left = 0, right = P; // 초기 셋업
    while(right <= S) { // 슬라이딩 윈도우
        bool chk = true;
        for(int i = 0; i < 4; i++) {
            if(count[i] < bound[i]) {
                chk = false;
                break;
            }
        } // 조건 4가지 만족했는지 체크
        if(chk)
            ans++; // 4가지 다 만족시 개수 추가
        count[getIndex(str[left])]--;
        count[getIndex(str[right])]++;
        left++;
        right++; // 슬라이딩 윈도우로 갱신
    }
    printf("%d\n", ans); // 개수 출력
    return 0;
}