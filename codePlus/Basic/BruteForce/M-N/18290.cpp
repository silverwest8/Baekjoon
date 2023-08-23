// https://www.acmicpc.net/problem/18290
// N*M 격자판에 들어있는 수 중 서로 인접하지 않는 K개의 칸의 수를 모두 더한 값의 최대값 구하기
// max 초기값 설정 후 DFS를 통해 해결, visited의 경우 int를 사용하여 이미 방문했거나 인접한 칸 구별

#include <iostream>
#include <vector>

int N, M, K, max = 0;
std::vector<std::vector<int>> v(10, std::vector<int>(10, 0));
std::vector<std::vector<int>> visited(10, std::vector<int>(10, false));
std::vector<int> v2;

void DFS(int sum) {
    if (v2.size() == K) {
        if (sum > max) max = sum;
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                visited[i][j]++;
                if (i+1 < N) visited[i+1][j]++;
                if (i-1 >= 0) visited[i-1][j]++;
                if (j+1 < M) visited[i][j+1]++;
                if (j-1 >= 0) visited[i][j-1]++;
                v2.emplace_back(v[i][j]);
                DFS(sum+v[i][j]);
                v2.pop_back();
                visited[i][j]--;
                if (i+1 < N) visited[i+1][j]--;
                if (i-1 >= 0) visited[i-1][j]--;
                if (j+1 < M) visited[i][j+1]--;
                if (j-1 >= 0) visited[i][j-1]--;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> v[i][j];
        }
    }
    max = -10000*std::min(4, N*M);
    DFS(0);
    std::cout << max;
    return 0;
}