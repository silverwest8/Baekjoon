#include <iostream>
#include <vector>

int N, S, count = 0;
std::vector<int> v;

void DFS(int sum, int idx) {
    if (idx == N) {
        return;
    } else {
        if (sum+v[idx] == S) { // 크기가 1 이상
            count++;
        }
        DFS(sum,        idx+1);
        DFS(sum+v[idx], idx+1);
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N >> S;

    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    DFS(0, 0);
    std::cout << count;
    return 0;
}