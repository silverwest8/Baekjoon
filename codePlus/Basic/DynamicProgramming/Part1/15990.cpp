// 2023. 8. 18. 20:20 - 21:39
#include <iostream>
#include <vector>
#define MAX 100000

int T, n;
std::vector<std::vector<unsigned long>> v(MAX+1, std::vector<unsigned long>(3+1, 0));
// std::vector<int> plus;

unsigned long DP(int n) {
    v[1][1] = 1; // 1로끝
    v[1][2] = 0; // 2로끝
    v[1][3] = 0; // 3으로끝

    v[2][1] = 0;
    v[2][2] = 1;
    v[2][3] = 0;

    v[3][1] = 1;
    v[3][2] = 1;
    v[3][3] = 1;
    for (int i = 4; i <= n; i++) {
        v[i][1] = (v[i-1][3] + v[i-1][2])%1000000009;
        v[i][2] = (v[i-2][1] + v[i-2][3])%1000000009;
        v[i][3] = (v[i-3][1] + v[i-3][2])%1000000009;
    }
    return (v[n][1] + v[n][2] + v[n][3])%1000000009;
}

/*
void DFS(int sum) {
    if (sum == n) {
        count++;
    } else {
        for (int i = 1; i <= 3; i++) {
            if (plus.size() == 0 || plus[plus.size()-1] != i) {
                if (sum+i > n) break;
                plus.emplace_back(i);
                DFS(sum+i);
                plus.pop_back();
            }
        }
    }
}
*/

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::cout << DP(n)%1000000009 << "\n";
    }
    return 0;
}