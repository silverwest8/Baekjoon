#include <string>
#include <vector>


using namespace std;

int N;
std::vector<int> visited;
std::vector<std::vector<int>> v;


void dfs(int n) {
    for (int i = 0; i < v[n].size(); i++) {
        if (!visited[v[n][i]]) {
            visited[v[n][i]] = true;
            dfs(v[n][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = computers.size();
    visited = std::vector<int>(N, false);
    
    for (int i = 0; i < N; i++) {
        v.emplace_back(std::vector<int>());
        for (int j = 0; j < computers[i].size(); j++) {
            if (i != j && computers[i][j] == 1) {
                v[i].emplace_back(j);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer++;
            dfs(i);
        }
    }
    return answer;
}