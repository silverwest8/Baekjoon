// 2023.8.16 20:59
// 다시풀기 -> 너무 복잡하게 풂
#include <iostream>
#include <vector>
#define MAX 100

int N, L, count = 0;
std::vector<std::vector<int>> v(MAX, std::vector<int>(MAX));
std::vector<std::vector<int>> ok(2, std::vector<int>(MAX, -1));
// std::vector<bool> ramp(MAX, false);
bool ramp[MAX] = {false, };

int main(int argc, char* argv[]) {
    std::cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> v[i][j];
        }
    }
    // 가로
    int temp, len, br;
    for (int i = 0; i < N; i++) {
        for (int l = 0; l < N; l++) {
            ramp[l] = false;
        }
        temp = 0;
        len = 0;
        for (int j = 0; j < N; j++) {
        // 길이가 모두 같거나 길이가 L인 경사로를 통해 길을 만들 수 있을 때(낮은곳 -> 높은곳, 왼->오)
            if (v[i][temp] == v[i][j]) {
                len++;
            } else {
                if (v[i][j-1] - v[i][j] == -1) {
                    if (len < L) { // 놓을 수 있는 공간이 없으면 불가
                        ok[0][i] = 0;
                        break;
                    }
                    for (int k = 1; k <= L; k++) {
                        ramp[j-k] = true;
                    }
                } 
                if (v[i][j-1] - v[i][j] != -1 && v[i][j-1] - v[i][j] != 1) { // 차이가 1이 아니면 원천 불가
                    ok[0][i] = 0;
                    break;
                } 
                temp = j;
                len = 1;
            }
            if (j == N-1) {
                if (ok[0][i] == -1) ok[0][i] = 1;
            }
        }
        temp = N-1;
        len = 0;
        br = 0;
        for (int j = N-1; j >= 0; j--) {
            // 길이가 모두 같거나 길이가 L인 경사로를 통해 길을 만들 수 있을 때(낮은곳 -> 높은곳, 오->왼)
            if (v[i][temp] == v[i][j]) {
                len++;
            } else {
                if (v[i][j] - v[i][j+1] == 1) {
                    if (len < L) { // 놓을 수 있는 공간이 없으면 불가
                        ok[0][i] = 0;
                        break;
                    }
                    for (int k = 1; k <= L; k++) {
                        if (!br) {
                            if (!ramp[j+k]) ramp[j+k] = true;
                            else {
                                ok[0][i] = 0;
                                br = 1;
                                break;
                            }
                        }
                    }
                    br = 0;
                } 
                if (v[i][j] - v[i][j+1] != -1 && v[i][j] - v[i][j+1] != 1) { // 차이가 1이 아니면 원천 불가
                    ok[0][i] = 0;
                    break;
                } 
                temp = j;
                len = 1;
            }
            if (j == 0) {
                if (ok[0][i] == -1) ok[0][i] = 1;
            }
        }
    }
    // 세로
    for (int j = 0; j < N; j++) {
        for (int l = 0; l < N; l++) {
            ramp[l] = false;
        }
        temp = 0;
        len = 0;
        for (int i = 0; i < N; i++) {
        // 길이가 모두 같거나 길이가 L인 경사로를 통해 길을 만들 수 있을 때(낮은곳 -> 높은곳, 위->아래)
            if (v[temp][j] == v[i][j]) {
                len++;
            } else {
                if (v[i-1][j] - v[i][j] == -1) {
                    if (len < L) { // 놓을 수 있는 공간이 없으면 불가
                        ok[1][j] = 0;
                        break;
                    }
                    for (int k = 1; k <= L; k++) {
                        ramp[i-k] = true;
                    }
                }
                if (v[i-1][j] - v[i][j] != -1 && v[i-1][j] - v[i][j] != 1) { // 차이가 1이 아니면 원천 불가
                    ok[1][j] = 0;
                    break;
                }
                temp = i;
                len = 1;
            }
            if (i == N-1) {
                if (ok[1][j] == -1) ok[1][j] = 1;
            }
        }
        temp = N-1;
        len = 0;
        br = 0;
        for (int i = N-1; i >= 0; i--) {
            // 길이가 모두 같거나 길이가 L인 경사로를 통해 길을 만들 수 있을 때(낮은곳 -> 높은곳, 아래->위)
            if (v[temp][j] == v[i][j]) {
                len++;
            } else {
                if (v[i][j] - v[i+1][j] == 1) {
                    if (len < L) { // 놓을 수 있는 공간이 없으면 불가
                        ok[1][j] = 0;
                        break;
                    }
                    for (int k = 1; k <= L; k++) {
                        if (!br) {
                            if (!ramp[i+k]) ramp[i+k] = true;
                            else {
                                ok[1][j] = 0;
                                br = 1;
                                break;
                            }
                        }
                    }
                    br = 0;
                }
                if (v[i][j] - v[i+1][j] != -1 && v[i][j] - v[i+1][j] != 1) { // 차이가 1이 아니면 원천 불가
                    ok[1][j] = 0;
                    break;
                }
                temp = i;
                len = 1;
            }
            if (i == 0) {
                if (ok[1][j] == -1) ok[1][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (ok[0][i] == 1) count++;
        if (ok[1][i] == 1) count++;
    }
    std::cout << count;
    return 0;
}