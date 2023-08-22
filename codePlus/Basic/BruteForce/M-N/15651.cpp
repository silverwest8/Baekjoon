// https://www.acmicpc.net/problem/15651
// 중복가능, 1-N중에서 M개

#include <iostream>
#define max 8

int N, M;
int arr[max+1];

void dfs(int depth) {
    int i;
    if (depth == M) {
        for (i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (i = 1; i <= N; i++) {
            arr[depth] = i;
            dfs(depth+1);
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M;
    dfs(0);
    return 0;
}