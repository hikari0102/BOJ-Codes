#include <iostream>

using namespace std;
// https://www.acmicpc.net/problem/2417

/*
#이분 탐색
이분 탐색으로 구현하면 되는 문제였는데 좀 오류사항이 있던 문제로 왜 틀린건지 몰?루다.
*/

int main() {
    unsigned long long int N;
    cin >> N;
    unsigned long long int left = 0, right = N / 2, mid = 0;
    if(N == 0) { // 0오류 처리
        cout << "0\n";
        return 0;
    }
    while(left <= right) { // 이분 탐색
        mid = (left + right) / 2;
        if(mid * mid >= N)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if(mid * mid < N) // q^2 < N이면 보정
        mid++;
    cout << mid << "\n";
    return 0;
}