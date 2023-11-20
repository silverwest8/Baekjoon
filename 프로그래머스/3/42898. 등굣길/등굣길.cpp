#include <string>
#include <vector>
#include <queue>

#define BIG 1000000007

int solution(int m, int n, std::vector<std::vector<int>> puddles) {
    long long answer = 0;
    int dp[101][101];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m ; j++){
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            long long a = 0, b = 0;
            if (i-1 > 0 && dp[i-1][j] != -1) {
                a = dp[i-1][j] % 1000000007;
            }
            if (j-1 > 0 && dp[i][j-1] != -1) {
                b = dp[i][j-1] % 1000000007;
            }
            dp[i][j] += (a+b) % 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}