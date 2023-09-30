#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int count = 0;
std::vector<int> v;

void dfs(int n, int sum) {
    if (sum == N) {
        count++;
        // std::cout << v.size() << "\n";
        // for (int i = 0; i < v.size(); i++) {
        //     std::cout << v[i] << " ";
        // }
        // std::cout << "\n";
        // std::cout << count << "\n";
        if (count == 1234567) {
            count = 0;
        }
        return;
    }
    for (int i = 1; i <= 2; i++) {
        v.emplace_back(i);
        if (sum+i <= N) {
            dfs(n+1, sum+i);
        }
        v.pop_back();
    }
}

long long solution(int n) {
    N = n;
    long long answer = 0;
    // dfs(0, 0);
    // answer = count;
    std::vector<int> dp(2000+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%1234567;
    }
    answer = dp[n];
    return answer;
}