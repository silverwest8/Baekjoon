// https://www.acmicpc.net/problem/15652
// 중복가능, 1-N중에서 M개, 비내림차순
// DFS를 사용하여 바로 이전 요소보다 크거나 같을 경우 삽입

#include <iostream>
#include <vector>

int N, M;
    std::vector<int> v;

void DFS() {
    if (v.size() == M) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (v.size() > 0) {
                if (v[v.size()-1] <= i) {
                    v.emplace_back(i);
                    DFS();
                    v.pop_back();
                }
            } else {
                v.emplace_back(i);
                DFS();
                v.pop_back();
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M;
    DFS();
    
    return 0;
}