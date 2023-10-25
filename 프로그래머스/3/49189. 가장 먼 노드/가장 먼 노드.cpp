#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20000

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    std::vector<std::vector<int>> v(n+1, std::vector<int>());
    std::vector<int> visited(n+1, false);
    std::queue<int> q;
    std::vector<int> dist(n+1, -1);
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].emplace_back(edge[i][1]);
        v[edge[i][1]].emplace_back(edge[i][0]);
    }
    
    q.push(1);
    visited[1] = true;
    dist[1] = 0;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < v[temp].size(); i++) {
            int target = v[temp][i];
            if (!visited[target]) {
                visited[target] = true;
                q.push(target);
                if (dist[target] == -1) {
                    dist[target] = dist[temp]+1;
                }
            }
        }
    }
    std::sort(dist.begin(), dist.end(), std::greater<>());
    
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == dist[0]) answer++;
    }
    return answer;
}