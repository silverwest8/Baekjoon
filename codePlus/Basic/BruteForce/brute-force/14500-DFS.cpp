// 2023.8.18 14:18 - 15:00
#include <iostream>
#include <vector>
#define MAX 1000

int N, M, max = 0;
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};
std::vector<std::vector<int>> v(MAX, std::vector<int>(MAX));
std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX));

void DFS(int n, int i, int j, int sum) {
    if (n == 3) {
        if (sum > max) max = sum;
    } else {
        for (int k = 0; k < 4; k++) {
            int x = i+dir1[k];
            int y = j+dir2[k];
            if (0 <= x && x < N && 0 <= y && y < M) {
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    DFS(n+1, x, y, sum+v[x][y]);
                    visited[x][y] = false;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(0, i, j, v[i][j]);
            visited[i][j] = false;
        }
    }

    //5-1
    for (int i = 0; i+1 < N; i++) {
        for (int j = 0; j+2 < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i][j+2];
            temp += v[i+1][j+1];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j+1];
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            temp += v[i+1][j+2];
            if (temp > max) max = temp;
        }
    }

    //5-3
    for (int i = 0; i+2 < N; i++) {
        for (int j = 0; j+1 < M; j++) {
            temp = 0;
            temp += v[i][j+1];
            temp += v[i+1][j+1];
            temp += v[i+2][j+1];
            temp += v[i+1][j];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i+2][j];
            temp += v[i+1][j+1];
            if (temp > max) max = temp;
        }
    }
    
    std::cout << max;
    return 0;
}