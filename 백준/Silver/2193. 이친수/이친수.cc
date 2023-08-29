#include <iostream>

unsigned long DP(int N) {
    unsigned long arr[91][2];
    arr[1][0] = 0;
    arr[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        arr[i][0] = arr[i-1][0]+arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    return arr[N][0]+arr[N][1];
}

int main(int argc, char* argv[]) {
    int N;
    std::cin >> N;
    std::cout << DP(N);
    return 0;
}