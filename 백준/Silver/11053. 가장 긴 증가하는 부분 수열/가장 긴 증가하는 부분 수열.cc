#include <iostream>
int arr[1000];
int dp[1000];

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

    std::cout << max;
    return 0;
}