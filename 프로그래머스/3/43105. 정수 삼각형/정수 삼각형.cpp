#include <string>
#include <vector>

int solution(std::vector<std::vector<int>> triangle) {
    std::vector<std::vector<int>> dp(triangle.size(), std::vector<int>(triangle.size(), 0));
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j <= i; j++) {
            int temp1 = 0, temp2 = 0;
            if (j-1 >= 0) {
                temp1 = dp[i-1][j-1];
            }
            temp2 = dp[i-1][j];
            dp[i][j] = std::max(temp1, temp2) + triangle[i][j];
        }
    }
    for (int i = 0; i < dp[dp.size()-1].size(); i++) {
        answer = std::max(answer, dp[dp.size()-1][i]);
    }
    return answer;
}