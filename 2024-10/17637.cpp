#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/17637
/*
#기하학 #해시를 이용한 집합과 맵
X좌표의 차이를 해시를 이용하여 각 차이 마다 개수가 얼마나 있는지 저장한 후, 
Y좌표의 점 2개 쌍에 대해서 점 2개의 차이만큼의 X좌표 쌍 개수 만큼 정사각형 추가
*/

int main() {
    map<int, int> x_cor_diff;
    int x_cors[1501] = {0};
    int y_cors[1501] = {0};
    int H, V;
    int ans = 0;
    scanf("%d %d", &H, &V);
    for(int i = 0; i < H; i++) {
        scanf("%d", &x_cors[i]);
        for(int j = 0; j < i; j++) {
            int diff = abs(x_cors[i] - x_cors[j]); // X좌표 차이
            if(x_cor_diff.find(diff) != x_cor_diff.end()) // 맵에 있으면
                x_cor_diff[diff]++; // 1더하기
            else // 맵에 없으면
                x_cor_diff.insert({diff, 1}); // 새로 추가
        }
    }
    for(int i = 0; i < V; i++) {
        scanf("%d", &y_cors[i]);
        for(int j = 0; j < i; j++) {
            int diff = abs(y_cors[i] - y_cors[j]); // Y좌표 차이
            if(x_cor_diff.find(diff) != x_cor_diff.end()) // Y좌표 차이가 맵에 존재 하면
                ans += x_cor_diff[diff]; // 그만큼 정사각형 추가
        }
    }
    printf("%d\n", ans);
    return 0;
}