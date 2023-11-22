#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>

int map[101][101];
int visited[101][101];
int count[101][101];
std::queue<std::vector<int>> q;

void bfs() {
    while(!q.empty()) {
        std::vector<int> temp = q.front();
        int x = temp[0];
        int y = temp[1];
        int cnt = count[x][y];
        q.pop();
        if (x+1 <= 100 && map[x+1][y] == 1 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            count[x+1][y] = cnt+1;
            std::vector<int> temp2;
            temp2.emplace_back(x+1);
            temp2.emplace_back(y);
            q.push(temp2);
        }
        if (x-1 >= 0 && map[x-1][y] == 1 && visited[x-1][y] == 0) {
            visited[x-1][y] = 1;
            count[x-1][y] = cnt+1;
            std::vector<int> temp2;
            temp2.emplace_back(x-1);
            temp2.emplace_back(y);
            q.push(temp2);
        }
        if (y+1 <= 100 && map[x][y+1] == 1 && visited[x][y+1] == 0) {
            visited[x][y+1] = 1;
            count[x][y+1] = cnt+1;
            std::vector<int> temp2;
            temp2.emplace_back(x);
            temp2.emplace_back(y+1);
            q.push(temp2);
        }
        if (y-1 >= 0 && map[x][y-1] == 1 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            count[x][y-1] = cnt+1;
            std::vector<int> temp2;
            temp2.emplace_back(x);
            temp2.emplace_back(y-1);
            q.push(temp2);
        }
    }
}

int solution(std::vector<std::vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][1]*2;
        int x2 = rectangle[i][3]*2;
        int y1 = rectangle[i][0]*2;
        int y2 = rectangle[i][2]*2;
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (x == x1 || x == x2 || y == y1 || y == y2) {
                    map[x][y] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][1]*2;
        int x2 = rectangle[i][3]*2;
        int y1 = rectangle[i][0]*2;
        int y2 = rectangle[i][2]*2;
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if ((x != x1 && x != x2) && (y != y1 && y != y2)) {
                    map[x][y] = 0;
                }
            }
        }
    }
    int cX = characterY*2;
    int cY = characterX*2;
    int iX = itemY*2;
    int iY = itemX*2;
    
    // for (int x = 0; x <= 20; x++) {
    //     for (int y = 0; y <= 20; y++) {
    //         std::cout << map[x][y] << " ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "\n\n";
    
    
    std::vector<int> temp;
    temp.emplace_back(cX);
    temp.emplace_back(cY);
    q.push(temp);
    visited[cX][cY] = 1;
    count[cX][cY] = 1;
    
    bfs();
    
    // for (int x = 0; x <= 20; x++) {
    //     for (int y = 0; y <= 20; y++) {
    //         // std::cout << count[x][y] << " ";
    //         std::printf("%3d", count[x][y]);
    //     }
    //     std::cout << "\n";
    // }
    
    answer = count[iX][iY]/2;
    return answer;
}