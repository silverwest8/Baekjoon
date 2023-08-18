// 2023 8 28 13:12 - 13:54
#include <iostream>
#include <vector>
#define MAX 1000

int N, M, max = 0;
std::vector<std::vector<int>> v(MAX, std::vector<int>(MAX));

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> v[i][j];
        }
    }

    //1
    for (int i = 0; i+1 < N; i++) {
        for (int j = 0; j+1 < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            if (temp > max) max = temp;
        }
    }
    //2 - 가로
    for (int i = 0; i < N; i++) {
        for (int j = 0; j+3 < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i][j+2];
            temp += v[i][j+3];
            if (temp > max) max = temp;
        }
    }
    //2 - 세로
    for (int i = 0; i+3 < N; i++) {
        for (int j = 0; j < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i+2][j];
            temp += v[i+3][j];
            if (temp > max) max = temp;
        }
    }
    //3 - 긴거
    for (int i = 0; i+2 < N; i++) {
        for (int j = 0; j+1 < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i+2][j];
            temp += v[i+2][j+1];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j+1];
            temp += v[i+1][j+1];
            temp += v[i+2][j+1];
            temp += v[i+2][j];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i+1][j];
            temp += v[i+2][j];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i+1][j+1];
            temp += v[i+2][j+1];
            if (temp > max) max = temp;
        }
    }
    //3 - 납작
    for (int i = 0; i+1 < N; i++) {
        for (int j = 0; j+2 < M; j++) {
            temp = 0;
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            temp += v[i+1][j+2];
            temp += v[i][j+2];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i][j+1];
            temp += v[i][j+2];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i][j+2];
            temp += v[i+1][j+2];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            temp += v[i+1][j+2];
            if (temp > max) max = temp;
        }
    }
    //4-1
    for (int i = 0; i+2 < N; i++) {
        for (int j = 0; j+1 < M; j++) {
            temp = 0;
            temp += v[i][j];
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            temp += v[i+2][j+1];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i+1][j];
            temp += v[i+2][j];
            temp += v[i][j+1];
            temp += v[i+1][j+1];
            if (temp > max) max = temp;
        }
    }
    //4-3
    for (int i = 0; i+1 < N; i++) {
        for (int j = 0; j+2 < M; j++) {
            temp = 0;
            temp += v[i][j+1];
            temp += v[i][j+2];
            temp += v[i+1][j];
            temp += v[i+1][j+1];
            if (temp > max) max = temp;

            temp = 0;
            temp += v[i][j];
            temp += v[i][j+1];
            temp += v[i+1][j+1];
            temp += v[i+1][j+2];
            if (temp > max) max = temp;
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