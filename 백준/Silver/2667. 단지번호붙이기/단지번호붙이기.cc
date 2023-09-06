#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 25

int N;
int v[MAX][MAX];
char v2[MAX][MAX];
int visited[MAX][MAX];

std::vector<int> result;

void bfs(int i, int j) {
    if (v[i][j] == 0) return;
    int sum = 0;
    std::queue<std::pair<int, int>> q;
    q.push(std::pair(i, j));
    while(!q.empty()) {
        std::pair<int, int> temp = q.front();
        q.pop();
        sum++;
        if (temp.first+1 < N && !visited[temp.first+1][temp.second] && v[temp.first+1][temp.second] != 0) {
            visited[temp.first+1][temp.second] = true;
            q.push(std::pair(temp.first+1, temp.second));
        }
        if (temp.first-1 >= 0 && !visited[temp.first-1][temp.second] && v[temp.first-1][temp.second] != 0) {
            visited[temp.first-1][temp.second] = true;
            q.push(std::pair(temp.first-1, temp.second));
        }
        if (temp.second+1 < N && !visited[temp.first][temp.second+1] && v[temp.first][temp.second+1] != 0) {
            visited[temp.first][temp.second+1] = true;
            q.push(std::pair(temp.first, temp.second+1));
        }
        if (temp.second-1 >= 0 && !visited[temp.first][temp.second-1] && v[temp.first][temp.second-1] != 0) {
            visited[temp.first][temp.second-1] = true;
            q.push(std::pair(temp.first, temp.second-1));
        }
    }
    result.emplace_back(sum);
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> v2[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v[i][j] = v2[i][j]-'0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                bfs(i, j);
                
            }
        }
    }

    std::sort(result.begin(), result.end());
    std::cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}