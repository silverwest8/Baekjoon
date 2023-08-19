// 2023.8.9 00:21 - 14:33
#include <iostream>
#include <vector>
#define MAX 10000

int N, max = 0, sum;
std::vector<int> P(MAX+1, 0);
std::vector<int> v(MAX+1, 0);
std::vector<int> dp(MAX+1, 0);

// DFS -> 시간 초과
void DFS(int count, int next) {
    if (count == N) {
        sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += P[v[i]];
        }
        if (sum > max) max = sum;
    } else if (count > N) {
        return;
    } else {
        for (int i = next; i <= N; i++) {
            v.emplace_back(i);
            DFS(count+i, i);
            v.pop_back();
        }
    }
}

int DP(int n) {
    dp[0] = 0;
    dp[1] = P[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = std::max(dp[i-j]+P[j], dp[i]);
        }
    }
    return dp[n];
}

int main(int argc, char* argdp[]) {
    int temp;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> temp;
        P[i] = temp;
    }
    // DFS(0, 1);
    std::cout << DP(N);
    return 0;
}