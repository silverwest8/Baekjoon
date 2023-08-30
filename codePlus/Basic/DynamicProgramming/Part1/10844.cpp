// https://www.acmicpc.net/problem/10844
// 길이가 N(1-100)인 계단수의 개수
// 이전 자리수의 양 옆 숫자로 끝나는 수를 더하면 본 자리수로 끝나는 수가 되는 규칙 활용 -> DP
// 주의 - start0 따로 할 필요 X

#include <iostream>
#define BIG 1000000000

unsigned long long arr[101][10];
// unsigned long long start0[101][10];

int main(int argc, char* argv[]) {
    int N;
    std::cin >> N;
    arr[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1; // 0으로 시작하는 계단수 포함
    }
    // start0[1][0] = 1; // 1자리 계단수 중 0으로 시작하는 수 중 0으로 끝나는 수
    // for (int i = 1; i <= 9; i++) {
    //     start0[1][i] = 0; 
    // }

    for (int i = 2; i <= 100; i++) {
        arr[i][0] = arr[i-1][1];
        arr[i][1] = (arr[i-1][1-1] + arr[i-1][1+1]) % BIG;
        arr[i][2] = (arr[i-1][2-1] + arr[i-1][2+1]) % BIG;
        arr[i][3] = (arr[i-1][3-1] + arr[i-1][3+1]) % BIG;
        arr[i][4] = (arr[i-1][4-1] + arr[i-1][4+1]) % BIG;
        arr[i][5] = (arr[i-1][5-1] + arr[i-1][5+1]) % BIG;
        arr[i][6] = (arr[i-1][6-1] + arr[i-1][6+1]) % BIG;
        arr[i][7] = (arr[i-1][7-1] + arr[i-1][7+1]) % BIG;
        arr[i][8] = (arr[i-1][8-1] + arr[i-1][8+1]) % BIG;
        arr[i][9] = arr[i-1][8];
    }

    unsigned long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result += arr[N][i];
        // result -= start0[N][i];
        result %= BIG;
    }
    std::cout << result;
    return 0;
}