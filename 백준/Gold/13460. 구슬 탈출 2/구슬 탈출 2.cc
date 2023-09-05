#include <iostream>
#include <vector>

int N, M;
int min = 11;
char map[10][10];
int xdir[] = {0, 0, 1, -1};
int ydir[] = {1, -1, 0, 0};

void move(int red[2], int blue[2], int dir, int cnt) {
    if (cnt > 10) return;
    int red_flg = 0;
    int blue_flg = 0;

    int red_temp[2] = {red[0], red[1]};
    int blue_temp[2] = {blue[0], blue[1]};
    
    while(map[red_temp[0]+xdir[dir]][red_temp[1]+ydir[dir]] != '#') {
        red_temp[0] = red_temp[0]+xdir[dir];
        red_temp[1] = red_temp[1]+ydir[dir];
        if (map[red_temp[0]][red_temp[1]] == 'O') {
            red_flg = 1;
            break;
        }
    }
    while(map[blue_temp[0]+xdir[dir]][blue_temp[1]+ydir[dir]] != '#') {
        blue_temp[0] = blue_temp[0]+xdir[dir];
        blue_temp[1] = blue_temp[1]+ydir[dir];
        if (map[blue_temp[0]][blue_temp[1]] == 'O') {
            blue_flg = 1;
            break;
        }
    }
    
    if (red_temp[0] == blue_temp[0] && red_temp[1] == blue_temp[1]) {
        if (dir == 0) {
            if (red[1] < blue[1]) {
                red_temp[1]--;
            } else {
                blue_temp[1]--;
            }
        } else if (dir == 1){
            if (red[1] < blue[1]) {
                blue_temp[1]++;
            } else {
                red_temp[1]++;
            }
        } else if (dir == 2) {
            if (red[0] < blue[0]) {
                red_temp[0]--;
            } else {
                blue_temp[0]--;
            }
        } else if (dir == 3){
            if (red[0] < blue[0]) {
                blue_temp[0]++;
            } else {
                red_temp[0]++;
            }
        }
    }
    if (red_temp[0] == red[0] && red_temp[1] == red[1] && blue_temp[0] == blue[0] && blue_temp[1] == blue[1]) {
        return;
    }

    if (blue_flg) {
        return;
    } else if (red_flg) {
        if (min > cnt) {
            min = cnt;
            return;
        }
    }
    // printMap(red, blue);

    for (int i = 0; i < 4; i++) {
        if (i == dir) continue;
        if (i == 0 && dir == 1) continue;
        if (i == 1 && dir == 0) continue;
        if (i == 2 && dir == 3) continue;
        if (i == 3 && dir == 2) continue;
        move(red_temp, blue_temp, i, cnt+1);
    }
}

int main(int argc, char* argv[]) {
    int red[2];
    int blue[2];
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'R') {
                red[0] = i;
                red[1] = j;
                map[i][j] = '.';
            } else if (map[i][j] == 'B') {
                blue[0] = i;
                blue[1] = j;
                map[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        move(red, blue, i, 1);
    }
    if (min <= 10) std::cout << min;
    else std::cout << -1;
    return 0;
}