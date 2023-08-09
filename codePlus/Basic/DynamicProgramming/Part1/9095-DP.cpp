// 11:37 - 12:18 DFS로 풂
// 다른 방법 - DP, 1,2,3만 이용하는거니까 규칙 찾아서 점화식 도출 가능(f(n) = f(n-1) + f(n-2) + f(n-3))
#include <iostream>
#include <numeric>
#include <vector>
#define max 10

int N, n, count;
std::vector<int> arr(max, 0);

int DP(int n) {
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::fill(arr.begin(), arr.end(), 0);
        count = 0;
        std::cin >> n;
        std::cout << DP(n) << "\n";
    }
    return 0;
}