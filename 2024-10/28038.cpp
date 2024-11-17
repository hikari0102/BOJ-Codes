#include <stdio.h>
#include <cmath>
#define PI 3.1415927

/*
https://www.acmicpc.net/problem/28038
#기하학 #수학
말 그대로 극좌표계 <-> 데카르트 좌표계의 변환을 구현하는 문제다.
acos의 범위를 헷갈려서 좀 애먹었던 문제다
*/

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        int mod;
        scanf("%d", &mod);
        if(mod == 1) { // 데카르트 -> 극좌표
            double x, y;
            scanf("%lf %lf", &x, &y);
            double r = sqrt(x * x + y * y); // 원점으로부터의 거리
            double angle;
            if(r != 0)
            {
                angle = acos(x / r); // 아크 코사인으로 값 구해주기
                if(y < 0) // y좌표 음수면 보정
                    angle = 2 * PI - angle;
            }
            else
                angle = 0; // 거리 0이면 하드코딩
            printf("%.8f %.8f\n", r, angle);
        }
        else {
            double r, angle;
            scanf("%lf %lf", &r, &angle);
            double x = r * cos(angle);
            double y = r * sin(angle);
            printf("%.8f %.8f\n", x, y);
        }
    }
    return 0;
}