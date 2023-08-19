// 2023.8.9. 00:03 - 00:10
#include <iostream>
#include <vector>

int N;
std::vector<int> v(9, 0);
std::vector<bool> visited(9, false);

void DFS(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v[depth] = i;
                DFS(depth+1);
                visited[i] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    DFS(0);
    return 0;
}