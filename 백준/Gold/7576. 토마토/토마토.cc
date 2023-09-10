#include <iostream>
#include <queue>
#define MAX 1000

int N, M;
int box[MAX][MAX];
int day[MAX][MAX];

int max = -1;
int xdir[4] = {1, -1, 0, 0};
int ydir[4] = {0, 0, 1, -1};
std::queue<std::pair<int, int>> q;

void bfs() {
    while(!q.empty()) {
        std::pair<int, int> temp;
        temp = q.front();   
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = temp.first + xdir[k];
            int y = temp.second + ydir[k];
            if (x >= 0 && y >= 0 && x < N && y < M && box[x][y] != -1 && day[temp.first][temp.second]+1 < day[x][y]) {
                day[x][y] = day[temp.first][temp.second]+1;
                q.push(std::make_pair(x, y));
            }
        }
    }
}

int main(int argc, char*argv[]) {
    std::cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> box[i][j];
            day[i][j] = 1000000;
            if (box[i][j] == 1) {
                day[i][j] = 0;
                q.push(std::make_pair(i, j));
            }
        }
    }
    
    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] != -1 && day[i][j] > max) max = day[i][j];
        }
    }

    if (max == 1000000) std::cout << -1;
    else std::cout << max;
    
    return 0;
}