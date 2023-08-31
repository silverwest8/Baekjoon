#include <iostream>
#include <vector>

int arr[1000];
int dp[1000];
std::vector<int> ans;

int main(int argc, char* argv[]) {
    int N, max = 1;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        int big = 1;
        int temp;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                temp = dp[j]+1;
                if (big < temp) big = temp;
            }
        }
        dp[i] = big;
        if (max < dp[i]) max = dp[i];
    }
    int max_save = max;
    for (int i = N-1; i >= 0; i--) {
        if (dp[i] == max_save) {
            ans.push_back(arr[i]);
            max_save--;
        }
    }

    std::cout << max << "\n";
    for (int i = max-1; i >= 0; i--) {
        std::cout << ans[i] << " ";
    }
    return 0;
}