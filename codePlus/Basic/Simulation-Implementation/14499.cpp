// 2023. 08.10 0:34 - 1:26
#include <iostream>
#define MAX 20

int N, M, x, y, K, k;
int top, bottom, front, back, left, right;
int arr[MAX][MAX];
enum Dir {EAST = 1, WEST = 2, NORTH = 3, SOUTH = 4};

void copyArr() {
    // 주사위를 굴렸을 때
    // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
    // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
    if (arr[x][y] == 0) {
        arr[x][y] = bottom;
    } else {
        bottom = arr[x][y];
        arr[x][y] = 0;
    }
    std::cout << top << "\n";
    return;
}

int main(int argc, char* argv[]) {
    int temp, i, j;
    std::cin >> N >> M >> x >> y >> K;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            std::cin >> temp;
            arr[i][j] = temp;
        }
    }
    for (i = 0; i < K; i++) {
        std::cin >> k;
        switch (k) {
            case EAST:
                if (y+1 >= M) break;
                y++;
                // top <- left // left <- bottom // bottom <- right // right <- top
                temp = top;
                top = left;
                left = bottom;
                bottom = right;
                right = temp;
                copyArr();
                break;
            case WEST:
                if (y-1 < 0) break;
                y--;
                // top <- right // right <- bottom // bottom <- left // left <- top
                temp = top;
                top = right;
                right = bottom;
                bottom = left;
                left = temp;
                copyArr();
                break;
            case NORTH:
                if (x-1 < 0) break;
                x--;
                // top <- front // front <- bottom // bottom <- back // back <- top
                temp = top;
                top = front;
                front = bottom;
                bottom = back;
                back = temp;
                copyArr();
                break;
            case SOUTH:
                if (x+1 >= N) break;
                x++;
                // top <- back // back <- bottom // bottom <- front // front <- top
                temp = top;
                top = back;
                back = bottom;
                bottom = front;
                front = temp;
                copyArr();
                break;
            default:
                break;
        }
    }
    return 0;
}