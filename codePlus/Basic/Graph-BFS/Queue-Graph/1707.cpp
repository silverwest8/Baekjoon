// 2023.8.20. 00:00 - 
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000
#define RED 1
#define BLUE 2

int K, V, E;
std::vector<std::vector<int>> v(MAX+1, std::vector<int>());
std::vector<int> visited(MAX+1, 0);

/*
void DFS(int n) {
    if (visited[n] == 0) visited[n] = RED;
    for (int i = 0; i < v[n].size(); i++) {
        if (visited[v[n][i]] == 0) {
            if (visited[n] == RED) visited[v[n][i]] = BLUE;
            if (visited[n] == BLUE) visited[v[n][i]] = RED;
            DFS(v[n][i]);
        }
    }
}
*/

void BFS(int n) {
    visited[n] = RED;
    std::queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            if (visited[v[now][i]] == 0) {
                q.push(v[now][i]);
                if (visited[now] == RED) visited[v[now][i]] = BLUE;
                else if (visited[now] == BLUE) visited[v[now][i]] = RED;
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (visited[i] == visited[v[i][j]]) return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    bool bipartite;
    int temp1, temp2;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        //초기화
        for (int x = 0; x <= V; x++) {
            v[x].clear();
        }
        for (int x = 0; x <= V; x++) {
            visited[x] = 0;
        }

        std::cin >> V >> E;
        for (int j = 0; j < E; j++) {
            std::cin >> temp1 >> temp2;
            v[temp1].emplace_back(temp2);
            v[temp2].emplace_back(temp1);
        }
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                BFS(i);
                // DFS(i);
            }
        }

        bipartite = check();
        if (bipartite) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;
}
