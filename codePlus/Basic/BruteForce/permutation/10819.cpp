// https://www.acmicpc.net/problem/10819
// |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|의 최대값
// DFS 사용

#include <iostream>
#include <vector>
#define ABS(x) (((x)<0) ? -(x) : (x))


int N, max;
std::vector<int> v, v2;
std::vector<bool> visited(8, false);

void DFS(int n, int sum) {
    if (n == N) {
        if (sum > max) max = sum;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            v2.emplace_back(v[i]);
            DFS(n+1, sum+ABS(v2[n-1]-v2[n]));
            v2.pop_back();
            visited[i] = false;
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        v2.emplace_back(v[i]);
        DFS(1, 0);
        v2.pop_back();
        visited[i] = false;
    }
    std::cout << max;
    
    return 0;
}