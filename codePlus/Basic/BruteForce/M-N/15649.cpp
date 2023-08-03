#include <iostream>
#define max 8

int N, M;
int arr[max+1] = {0, };
bool visited[max+1] = {false, };

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[depth] = i;
                dfs(depth+1);
                visited[i] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M;
    dfs(0);
    return 0;
}