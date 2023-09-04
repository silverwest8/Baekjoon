#include <iostream>
#define MAX 1000000
#define MOD 1000000009

int main(int argc, char* argv[]) {
    int T, n;
    unsigned long DP[MAX+1];
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;
        for (int i = 4; i <= n; i++) {
            DP[i] = (DP[i-1] + DP[i-2] + DP[i-3]) % MOD;
        }
        std::cout << DP[n] << "\n";
    }
    return 0;
}