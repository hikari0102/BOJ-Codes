#include <stdio.h>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/10495

int gcd(int a, int b) {
    int r = a % b;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    } 
    return a;
} // 유클리드 호제법

int main() {
    while(1) { 
        int n;
        int eof_chk = scanf("%d", &n); // eof 체크
        if(eof_chk == -1)
            break; // eof면 종료
        int arr[1001];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + n); // 정렬
        int ans = arr[0]; // 초기 정답 제일 작은 걸로 하는건데 다른 걸로 해도 될려나??
        for(int i = n - 1; i >= 0; i--) { // 큰것부터(그리디)
            int chk = 0;
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(gcd(arr[i], arr[j]) != 1) { // 하나라도 gcd 1 이상인거 있으면 정답 아니니까 패스
                    chk = 1;
                    break;
                }
            }
            if(chk == 0) { // 정답나오면 바로 for문 탈출(정렬해서 큰 순서대로 나옴)
                ans = max(ans, arr[i]);
                break;
            }
        }
        printf("%d\n", ans);
    }
}