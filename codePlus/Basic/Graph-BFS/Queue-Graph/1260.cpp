#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000

int N, M;
std::vector<int> v[MAX+1];
std::vector<int> v2;
std::queue<int> q;
bool visited[MAX+1] = {false, };
bool visited2[MAX+1] = {false, };

/*
void DFS(int n, int start) {
    if (n == count) {
        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << " ";
        }
        std::cout << "\n";
    } else {
        if (!visited[start]) {
            visited[start] = true;
            v2.emplace_back(start);
            for (int i = 0; i < v[start].size(); i++) {
                DFS(n+1, v[start][i]);
            }
            v2.pop_back();
            visited[start] = false;
        }
    }
}
*/

// 시작 노드가 주어지면 그냥 바로바로 출력하면 됨. 굳이 vector를 완성시킬 필요 없음
void DFS(int start) {
    std::cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < v[start].size(); i++) {
        if (!visited[v[start][i]]) {
            DFS(v[start][i]);
        }
    }
}

void BFS(int start) {
    q.push(start);
    visited2[start] = true;
    while(q.size()) {
        int pop = q.front();
        std::cout << pop << " ";
        q.pop();
        for (int i = 0; i < v[pop].size(); i++) {
            if (!visited2[v[pop][i]]) {
                q.push(v[pop][i]);
                visited2[v[pop][i]] = true;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int start, temp1, temp2;
    std::cin >> N >> M >> start;
    for (int i = 0; i < M; i++) {
        std::cin >> temp1 >> temp2;
        v[temp1].emplace_back(temp2);
        v[temp2].emplace_back(temp1);
    }
    for (int i = 1; i <= N; i++) {
        std::sort(v[i].begin(), v[i].end());
    }

    DFS(start);
    std::cout << "\n";
    BFS(start);

    return 0;
}