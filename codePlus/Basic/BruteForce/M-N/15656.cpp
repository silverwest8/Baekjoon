// https://www.acmicpc.net/problem/15656
// N개 중 M개, 중복가능
// DFS를 사용하여 구현

#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> v;
std::vector<int> v2;

void DFS() {
    if (v2.size() == M) {
        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 0; i < v.size(); i++) {
            v2.emplace_back(v[i]);
            DFS();
            v2.pop_back();
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