#include <stdio.h>

// https://www.acmicpc.net/problem/1490
/*
#브루트포스
시간이 오래 걸릴것 같으나 1, 2, 3, ... 9의 최소 공배수가 2520이므로 적어도 N + 2520전에는 답이 나온다. 
*/

long long int mul(int exp) {
    if(exp == 1)
        return 10;
    if(exp % 2 == 0) {
        long long int half = mul(exp / 2);
        return half * half;
    }
    else
        return mul(exp - 1) * 10;
} // 10의 거듭제곱

int main() {
    bool chk[10];
    long long int N;
    long long int ans = -1;
    scanf("%lld", &N);
    long long int temp = N;
    bool chk2 = true;
    for(int i = 0; i < 10; i++)
        chk[i] = false; // 자리수 초기화 (이거 안해서 틀림)
    while(temp > 0) {
        chk[temp % 10] = true;
        temp /= 10;
    } // 자리수 체크
    for(int i = 2; i < 10; i++) {
        if(chk[i]) {
            if(N % i != 0) {
                chk2 = false;
                break;
            }
        }
    } // 자기 자신 체크
    if(chk2)
        ans = N;
    int e = 1;
    if(ans == -1) { // 자기 자신 검사했는데 답 아니면 (자기자신 답인데도 이거 돌리게 해서 틀림)
        while(1) {
            long long int ext = mul(e); // 1~9, 10~99, ... 식으로 뒤에 붙여서 테스트 해봄
            for(int i = 0; i < ext; i++) {
                long long int next = N * ext + i; // 뒤에 붙인 숫자
                bool isAns = true;
                for(int j = 2; j < 10; j++) {
                    if(chk[j]) {
                        if(next % j != 0) {
                            isAns = false;
                            break;
                        }
                    }
                } // 나눠지는지 체크 후
                if(isAns) {
                    ans = next; // 답이면 답으로 저장후 반복문 탈출
                    break;
                }
            }
            if(ans != -1)
                break; // 답 있으면 반복문 탈출 (이거 안해서 틀림)
            e++;
        }
    }
    printf("%lld\n", ans); // 답 출력
    return 0;
}