// https://www.acmicpc.net/problem/6603
// 1-49까지 수 중에 k개를 고른 뒤 그중에서 6개를 선택하는 조합 모두 출력
// DFS, visited 사용
// 주의 -> 테케 여러개일 때 vector 초기화 할 것

#include <iostream>
#include <vector>
#include <algorithm>

int k;
bool visited[50] = {false, };
std::vector<int> v;

void DFS(int n, int next) {
    if (n == 6) {
        for (int i = 0; i < k; i++) {
            if (visited[i]) std::cout << v[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = next; i < k; i++) {
        if (!visited[i]) {
            visited[i] = true;
            // v2.emplace_back(i);
            DFS(n+1, i+1);
            // v2.pop_back();
            visited[i] = false;
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int temp;
    while (true) {
        std::cin >> k;
        if (k == 0) break;
        v.clear();
        for (int i = 0; i < k; i++) {
            std::cin >> temp;
            v.emplace_back(temp);
        }
        std::sort(v.begin(), v.end());
        DFS(0, 0);
        std::cout << "\n";
    }

    return 0;
}