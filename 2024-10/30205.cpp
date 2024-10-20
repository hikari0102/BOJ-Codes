#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/30205

int main() {
    int N, M;
    long P;
    vector<int> buildings[501];
    scanf("%d %d %ld", &N, &M, &P);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            buildings[i].push_back(x);
        }
    }
    int chk = 1;
    for(int i = 0; i < N; i++) {
        int items = 0;
        sort(buildings[i].begin(), buildings[i].end()); // 순서 대로 정렬
        for(int j = 0; j < M; j++) {
            if(buildings[i][j] == -1) { // -1이면 아이템
                items++;
                if(j == M - 1 && items > 0) { // 아이템 남았으면 다쓰고 가기
                    while(items > 0) {
                        items--;
                        P *= 2;
                    }
                }
                continue;
            }
            if(buildings[i][j] <= P) // 적군 전투력이 현재 전투력보다 낮거나 같으면
                P += buildings[i][j]; // 전투력 상승
            else { // 적군 전투력이 현재 전투력보다 높으면
                while(P < buildings[i][j] && items > 0) { // 현재 전투력이 적군 전투력 보다 높아질때까지 아이템 사용
                    items--;
                    P *= 2;
                }
                if(P < buildings[i][j]) { // 아이템 다 써도 적군 못 이기면
                    chk = 0; // 임무 실패
                    break;
                }
                else 
                    P += buildings[i][j]; // 아니면 이겨서 전투력 상승
            }
            if(j == M - 1 && items > 0) { // 건물 다 돌았는데 아이템 남았으면
                while(items > 0) {
                    items--;
                    P *= 2; // 아이템 다 쓰고 가기
                }
            }
        }
    }
    printf("%d\n", chk);
    return 0;
}