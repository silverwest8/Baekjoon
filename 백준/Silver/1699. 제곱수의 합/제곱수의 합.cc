#include <iostream>

int main(int argc, char* argv[]) {
    int N;
    int dp[100001];
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
    }
    for (int i = 1; i*i <= N; i++) {
        dp[i*i] = 1;
        for (int j = 1; (i*i)+j <= N; j++) {
            dp[(i*i)+j] = std::min(dp[(i*i)+j], dp[i*i]+dp[j]);
        }
    }
    std::cout << dp[N];
    
    return 0;
}
