#include <string>
#include <vector>

std::vector<int> v;
std::vector<bool> visited;
int max = 0;

void dfs(int n, int now, std::vector<std::vector<int>> dungeons) {
    if (n > max) {
        max = n;
    }
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= now) {
            visited[i] = true;
            v.emplace_back(i);
            dfs(n+1, now-dungeons[i][1], dungeons);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int k, std::vector<std::vector<int>> dungeons) {
    int answer = -1;
    for (int i = 0; i < dungeons.size(); i++) {
        visited.emplace_back(false);
    }
    
    dfs(0, k, dungeons);
    answer = max;
    
    return answer;
}