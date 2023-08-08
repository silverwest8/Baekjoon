// 15:53 시작
#include <iostream>
#include <vector>
#define MAX 15

int N, max = 0;
std::vector<int> T(MAX+1, 0);
std::vector<int> P(MAX+1, 0);
std::vector<int> v(MAX+1, 0);
// 해당 날짜의 최대 보수

void DP() {
    for (int i = N; i >= 1; i--) {
        if (i+T[i] <= N+1) { // 가능
            v[i] = std::max(v[i+1], v[i+T[i]] + P[i]);
            // 다음날꺼부터 그대로 vs 그날 꺼 해서 받는 보수의 합 중 큰 것
        } else { // 불가능
            v[i] = v[i+1];
            // 다음날꺼 그대로
        }
        max = std::max(max, v[i]);
    }
}

int main(int argc, char* argv[]) {
    int t, p;
    std::cin >> N;
    T[0] = 0; P[0] = 0; v[0] = 0;
    for (int i = 1; i <= N; i++) {
        std::cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }
    DP();
    std::cout << max;
    return 0;
}