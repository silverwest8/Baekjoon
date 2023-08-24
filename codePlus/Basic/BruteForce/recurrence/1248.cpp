// https://www.acmicpc.net/problem/1248
// 1-10 사이의 N과 부호 행렬이 주어졌을 때, 이를 만족하는 서로 다른 정수의 수열 찾기

#include <iostream>
#include <vector>
#include <string>
#define MAX 10
int N, find = 0;
std::vector<std::vector<char>> sign(MAX, std::vector<char>(MAX, 0));
std::vector<int> v(MAX);

bool check(int n) {
    int temp = 0;
    for (int i = n; i >= 0; i--) {
        temp += v[i];
        if (sign[i][n] == '+' && temp <= 0) return false;
        if (sign[i][n] == '-' && temp >= 0) return false;
        if (sign[i][n] == '0' && temp != 0) return false;
    }
    return true;
}

// n개를 채운 후에 조건을 체크하는 것이 아니라 하나씩 넣으면서 체크하고 넣는 숫자 확정시키기
void DFS(int n) {
    if (!find) {
        if (n == N) {
            find = 1;
            for (int i = 0; i < N; i++) {
                std::cout << v[i] << " ";
            }
            std::cout << "\n";
            return;
        }
        for (int i = -10; i <= 10; i++) {
            v[n] = i;
            if (check(n)) {
                DFS(n+1);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string temp;
    std::cin >> N;
    std::cin >> temp;
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sign[i][j] = temp[k++];
        }
    }
    DFS(0);
    return 0;
}


/*
// 시간초과 -> -10부터 10까지 모두 넣어보고 찾으면 21^N회 탐색해야함
void DFS_fail(int n) {
    if (!find) {
        if (n == N) {
            for (int i = 0; i < N; i++) {
                int temp = 0;
                for (int j = i; j < N; j++) {
                    temp += v[j];
                    if ((sign[i][j] == '+' && temp <= 0) || (sign[i][j] == '-' && temp >= 0) || (sign[i][j] == '0' && temp != 0)) {
                        return;
                    }
                }
            }
            find = 1;
            for (int i = 0; i < N; i++) {
                std::cout << v[i] << " ";
            }
            std::cout << "\n";
            return;
        }
        for (int i = -10; i <= 10; i++) {
            if (!visited[i+10]) {
                visited[i+10] = true;
                v[n] = i;
                DFS_fail(n+1);
                visited[i+10] = false;
            }
        }
    }
}

// 마찬가지로 시간초과
void DFS_fail2(int n) {
    if (!find) {
        if (n == N+1) {
            for (int i = 1; i <= N; i++) {
                int temp = 0;
                for (int j = i; j <= N; j++) {
                    temp += v[j];
                    if ((sign[i][j] == '+' && temp <= 0) || (sign[i][j] == '-' && temp >= 0) || (sign[i][j] == '0' && temp != 0)) {
                        return;
                    }
                }
            }
            find = 1;
            for (int i = 1; i <= N; i++) {
                std::cout << v[i] << " ";
            }
            std::cout << "\n";
            return;
        }
        if (sign[n][n] == '+') {
            for (int i = 1; i <= 10; i++) {
                if (!visited[i+10]) {
                    visited[i+10] = true;
                    v[n] = i;
                    DFS_fail2(n+1);
                    visited[i+10] = false;
                }

            }
        } else if (sign[n][n] == '-') {
            for (int i = -1; i >= -10; i--) {
                if (!visited[i+10]) {
                    visited[i+10] = true;
                    v[n] = i;
                    DFS_fail2(n+1);
                    visited[i+10] = false;
                }
            }
        } else if (sign[n][n] == '0') {
            if (!visited[10]) {
                visited[10] = true;
                v[n] = 0;
                DFS_fail2(n+1);
                visited[10] = false;
            }
        }
    }
}

*/