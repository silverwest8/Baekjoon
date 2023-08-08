// 11:37 - 12:18 DFS로 풂
// 다른 방법 - DP, 1,2,3만 이용하는거니까 규칙 찾아서 점화식 도출 가능(f(n) = f(n-1) + f(n-2) + f(n-3))
#include <iostream>
#include <numeric>
#include <vector>
#define max 10

int N, n, count;
std::vector<int> arr(10, 0);

void dfs(int depth) {
    if (std::accumulate(arr.begin(), arr.end(), 0) == n) {
        count++;
    } else {
        if (depth >= n || std::accumulate(arr.begin(), arr.end(), 0) > n) {
            return;
        }
        for (int i = 1; i <= 3; i++) {
            arr[depth] = i;
            dfs(depth+1);
            arr[depth] = 0;
        }
    }
}

// sum을 인자로 하면 더 간결함
void DFS(int sum) {
    if (sum == n) {
        count++;
    } else if (sum > n) {
        return;
    } else {
        for (int i = 1; i <= 3; i++) {
            DFS(sum+i);
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        count = 0;
        // std::fill(arr.begin(), arr.end(), 0);
        DFS(0);
        std::cout << count << "\n";
    }
    return 0;
}