#include <iostream>
#define BIG 1000000000

unsigned long long arr[101][10];

int main(int argc, char* argv[]) {
    int N;
    std::cin >> N;
    arr[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1; // 0으로 시작하는 계단수 포함
    }
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
        result %= BIG;
    }
    std::cout << result;
    return 0;
}