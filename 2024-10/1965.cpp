#include <stdio.h>

/*
https://www.acmicpc.net/problem/1965
#dp #LIS
문제를 잘 읽어보면 LIS길이를 구하면 된다. 
*/

int arr[1001];
int lis[1001];
int cnt = 0;

int binary_search(int value) {
    int left = 0, right = cnt;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(lis[mid] >= value) {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
} // 이진 탐색

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    cnt++;
    lis[0] = arr[0];
    for(int i = 1; i < N; i++) {
        if(lis[cnt - 1] < arr[i]) { // LIS의 끝이 현재 원소보다 작으면 
            lis[cnt] = arr[i];
            cnt++;
        }
        else {  // LIS의 끝이 현재 원소보다 크면 
            int idx = binary_search(arr[i]);
            lis[idx] = arr[i];
        }
    }
    printf("%d\n", cnt);
}