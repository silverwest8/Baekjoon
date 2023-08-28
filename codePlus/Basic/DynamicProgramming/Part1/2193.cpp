// https://www.acmicpc.net/problem/2193
// N(1~90)자리 이친수(0으로 시작하지 않고 1이 두 번 연속으로 나타나지 않는 수)의 개수
// unsigned long에 주의

#include <iostream>

unsigned long DP(int N) {
    unsigned long arr[91][2];
    arr[1][0] = 0;
    arr[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        arr[i][0] = arr[i-1][0]+arr[i-1][1];
        arr[i][1] = arr[i-1][0];
        // 또는 arr[i] = arr[i-1] + arr[i-2] // 피보나치
    }
    return arr[N][0]+arr[N][1];
}

int main(int argc, char* argv[]) {
    int N;
    std::cin >> N;
    std::cout << DP(N);
    return 0;
}