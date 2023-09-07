#include <iostream>
#include <queue>
#define MAX 100
int N, M;
char arr2[MAX][MAX];
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int xdir[] = {1, -1, 0, 0};
int ydir[] = {0, 0, 1, -1};

void bfs(int i, int j) {
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(i, j));
    while(!q.empty()) {
        std::pair<int, int> temp = q.front();
        q.pop();
        int x, y;
        for (int k = 0; k < 4; k++) {
            x = temp.first+xdir[k];
            y = temp.second+ydir[k];
            if (x < N && x >= 0 && y < M && y >= 0 && !visited[x][y] && arr[x][y] == 1) {
                visited[x][y] = true;
                dist[x][y] = dist[temp.first][temp.second]+1;
                q.push(std::make_pair(x, y));
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> arr2[i][j];
            arr[i][j] = arr2[i][j]-'0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = 1;
        }
    }

    visited[0][0] = true;
    bfs(0, 0);
    std::cout << dist[N-1][M-1];
    return 0;
}