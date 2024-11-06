#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/12731
/*
시간표를 출발 시간에 따라서 정렬한 다음 우선순위 큐를 이용해서 도착한 열차들의 출발 가능 시간을 역별로 저장해서 시뮬레이션 돌려가는 방식으로 구현
근데 우선 순위 큐 이거 반대로 들어가는 것을 놓쳐서 헤맸음...
*/

int main() {
    int N;
    scanf("%d", &N);
    for(int T = 0; T < N; T++) {
        int na, nb, t;
        scanf("%d", &t);
        scanf("%d %d", &na, &nb);
        vector<pair<pair<int, int>, int>> times; // 시간들
        priority_queue<int> apq; // A역 큐
        priority_queue<int> bpq; // B역 큐
        for(int i = 0; i < na + nb; i++) {
            int a, b, c, d;
            scanf("%2d:%2d %2d:%2d", &a, &b, &c, &d);
            if(i < na)
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 1));
            else
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 2)); // 출발 시간, 도착 시간, 역 정보
        }
        sort(times.begin(), times.end()); // 정렬
        int aans = 0, bans = 0;
        for(int i = 0; i < na + nb; i++) {
            if(times[i].second == 1) { // A->B면
                if(!apq.empty()) {
                    if(-(apq.top()) <= times[i].first.first) // A역의 큐에 출발시간보다 빨리 도착한 것이 있는가?
                        apq.pop(); //있다면 큐에서 빼기
                    else 
                        aans++; // 없다면 A역에서 차량 1대 출발
                }
                else
                    aans++; // 없다면 A역에서 차량 1대 출발
                bpq.push(-(times[i].first.second + t)); // B역의 큐에 도착시간 + 회차 시간에 출발하는 열차에 push
            }
            else {
                if(!bpq.empty()) { 
                    if(-(bpq.top()) <= times[i].first.first) //B역의 큐에 출발시간보다 빨리 도착한 것이 있는가?
                        bpq.pop(); //있다면 큐에서 빼기
                    else 
                        bans++;  // 없다면 B역에서 차량 1대 출발
                }
                else
                    bans++;
                apq.push(-(times[i].first.second + t)); // A역의 큐에 도착시간 + 회차 시간에 출발하는 열차에 push
            }
        }
        printf("Case #%d: %d %d\n", T + 1, aans, bans);
    }
    return 0;
}