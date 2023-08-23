// https://www.acmicpc.net/problem/15654
// N개의 자연수 중 M개
// 사전 순 증가

#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> v;
std::vector<bool> visited(8, false);
std::vector<int> v2;

void DFS() {
    if (v2.size() == M) {
        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 0; i < v.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                v2.emplace_back(v[i]);
                DFS();
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
    DFS();
    
    return 0;
}