#include <iostream>
#include <vector>
#define MAX 1000

int N, M, count;
std::vector<std::vector<int>> graph(MAX+1);
std::vector<bool> visited(MAX+1);

void DFS(int n, int next) {
    visited[next] = true;
    for (int i = 0; i < graph[next].size(); i++) {
        if (!visited[graph[next][i]]) {
            DFS(n, graph[next][i]);
        }
    }
}

int main(int argc, char* argv[]) {
    int temp1, temp2;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> temp1 >> temp2;
        graph[temp1].emplace_back(temp2);
        graph[temp2].emplace_back(temp1);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count++;
            DFS(i, i);
        }
    }
    std::cout << count;
    return 0;
}