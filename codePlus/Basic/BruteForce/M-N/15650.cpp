#include <iostream>
#define max 8

int N, M;
int arr[max+1];

/*
bool visited[max+1];

void dfs(int start, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = start; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[depth] = i;
                dfs(i, depth+1);
                visited[i] = false;
            }
        }
    }
}
*/

void dfs(int start, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = start; i <= N; i++) {
            arr[depth] = i;
            dfs(i+1, depth+1);
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M;
    dfs(1, 0);
    return 0;
}

/*
void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (depth == 0 || i > arr[depth-1]) {
                    arr[depth] = i;
                    dfs(depth+1);
                }
                visited[i] = false;
            }
        }
    }
}
*/
// dfs(0);