#include <iostream>

#define MAX 200
#define MOD 1000000000
unsigned long arr[MAX+1][MAX+1];
int N, K;

int main(int argc, char* argv[]) {
    std::cin >> N >> K;
    for (int i = 1; i <= MAX; i++) {
        arr[1][i] = 1;
        arr[i][1] = i;
    }
    for (int i = 2; i <= K; i++) {
        for (int j = 2; j <= N; j++) {
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % MOD;
        }
    }
    std::cout << arr[K][N];
    return 0;
}