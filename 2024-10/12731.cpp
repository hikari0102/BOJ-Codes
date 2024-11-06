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
        vector<pair<pair<int, int>, int>> times;
        priority_queue<int> apq;
        priority_queue<int> bpq;
        for(int i = 0; i < na + nb; i++) {
            int a, b, c, d;
            scanf("%2d:%2d %2d:%2d", &a, &b, &c, &d);
            if(i < na)
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 1));
            else
                times.push_back(make_pair(make_pair(a * 60 + b, c * 60 + d), 2));
        }
        sort(times.begin(), times.end());
        int aans = 0, bans = 0;
        for(int i = 0; i < na + nb; i++) {
            if(times[i].second == 1) {
                if(!apq.empty()) {
                    if(-(apq.top()) <= times[i].first.first)
                        apq.pop();
                    else 
                        aans++;
                }
                else
                    aans++;
                bpq.push(-(times[i].first.second + t));
            }
            else {
                if(!bpq.empty()) {
                    if(-(bpq.top()) <= times[i].first.first)
                        bpq.pop();
                    else 
                        bans++;
                }
                else
                    bans++;
                apq.push(-(times[i].first.second + t));
            }
        }
        printf("Case #%d: %d %d\n", T + 1, aans, bans);
    }
    return 0;
}