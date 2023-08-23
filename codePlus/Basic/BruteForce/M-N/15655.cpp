// https://www.acmicpc.net/problem/15655
// N개 중 M개, 오름차순
// DFS, visited 사용하여 구현

#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> v;
std::vector<int> v2;
std::vector<bool> visited(8, false);

void DFS(int start) {
    if (v2.size() == M) {
        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = start; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                v2.emplace_back(v[i]);
                DFS(i+1);
                v2.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    std::sort(v.begin(), v.end());
    DFS(0);
    
    return 0;
}