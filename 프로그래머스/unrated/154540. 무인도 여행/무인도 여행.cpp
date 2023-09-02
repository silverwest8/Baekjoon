#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
std::vector<int> v;
std::queue<std::pair<int, int>> q;

void check(int x, int y, std::vector<std::string> &maps, std::vector<std::vector<bool>> &visited) {
    if (visited[x][y]) {
        return;
    }
    if (maps[x][y] == 'X') {
        visited[x][y] = true;
        return;
    }
    int sum = 0;
    visited[x][y] = true;
    q.push(std::pair(x, y));
    while(q.size()) {
        std::pair<int, int> temp = q.front();
        q.pop();
        sum += maps[temp.first][temp.second]-'0';
        if (temp.first+1 < N && !visited[temp.first+1][temp.second] && maps[temp.first+1][temp.second] != 'X') {
            visited[temp.first+1][temp.second] = true;
            q.push(std::pair(temp.first+1, temp.second));
        }
        if (temp.first-1 >= 0 && !visited[temp.first-1][temp.second] && maps[temp.first-1][temp.second] != 'X') {
            visited[temp.first-1][temp.second] = true;
            q.push(std::pair(temp.first-1, temp.second));
        }
        if (temp.second+1 < M && !visited[temp.first][temp.second+1] && maps[temp.first][temp.second+1] != 'X') {
            visited[temp.first][temp.second+1] = true;
            q.push(std::pair(temp.first, temp.second+1));
        }
        if (temp.second-1 >= 0 && !visited[temp.first][temp.second-1] && maps[temp.first][temp.second-1] != 'X') {
            visited[temp.first][temp.second-1] = true;
            q.push(std::pair(temp.first, temp.second-1));
        }
    }
    v.emplace_back(sum);
}

std::vector<int> solution(std::vector<std::string> maps) {
    std::vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check(i, j, maps, visited);
        }
    }
    
    if (!v.size()) v.emplace_back(-1);
    std::sort(v.begin(), v.end());
    return v;
}