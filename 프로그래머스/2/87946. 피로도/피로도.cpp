#include <string>
#include <vector>
#include <iostream>

int N;
std::vector<int> v;
std::vector<bool> visited;
int max = 0;

void dfs(int n, int now, std::vector<std::vector<int>> dungeons) {
    // std::cout << n << " " << now << "\n";
    if (n > max) {
        max = n;
        
    }
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            v.emplace_back(i);
            if (dungeons[i][0] <= now) {
                // std::cout << "add " << i << "\n";
                dfs(n+1, now-dungeons[i][1], dungeons);
            }
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int k, std::vector<std::vector<int>> dungeons) {
    int answer = -1;
    N = dungeons.size();
    for (int i = 0; i < dungeons.size(); i++) {
        visited.emplace_back(false);
    }
    
    dfs(0, k, dungeons);
    answer = max;
    
    return answer;
}