// https://www.acmicpc.net/problem/14391
// 최대 4*4 종이를 세로나 가로의 크기가 1인 직사각형으로 조각낼 때 이어붙인 숫자의 최대값
// 비트마스크/완전탐색 사용 -> 1~1<<N*M에 대하여 값 계산 후 최대값 결정

#include <iostream>
#include <string>

char v[4][4];
int N, M, max;

int main(int argc, char* argv[]) {
    std::string slice;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> v[i][j];
        }
    }

    // bitmask
    // 0은 가로, 1은 세로
    for (int p = 0; p < (1 << N*M); p++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int j = 0; j < M; j++) {
                int k = i*M + j;
                if ((p & (1 << k)) == 0) {
                    temp = temp*10 + v[i][j]-'0';
                } else {
                    sum+=temp;
                    temp = 0;
                }
            }
            sum+=temp;
        }

        for (int j = 0; j < M; j++) {
            int temp = 0;
            for (int i = 0; i < N; i++) {
                int k = i*M + j;
                if ((p & (1 << k)) != 0) {
                    temp = temp*10 + v[i][j]-'0';
                } else {
                    sum+=temp;
                    temp = 0;   
                }
            }
            sum+=temp;
        }
        if (sum > max) max = sum;
    }

    std::cout << max;
    return 0;
}

// 길게만 자르면 된다고 생각 -> 예외 있으므로 모든 케이스 적용 X
// 001
// 000
// 100
/*
    if (N == M) {
        // 가로
        temp = 0;
        for (int i = 0; i < N; i++) {
            slice = "";
            for (int j = 0; j < M; j++) {
                slice += std::to_string(v[i][j]-48);
            }
            temp += std::stoi(slice);
        }

        // 세로
        temp2 = 0;
        for (int j = 0; j < M; j++) {
            slice = "";
            for (int i = 0; i < N; i++) {
                slice += std::to_string(v[i][j]-48);
            }
            temp2 += std::stoi(slice);
        }
        max = std::max(temp, temp2);
    } else if (N > M) {
        max = 0;
        for (int j = 0; j < M; j++) {
            slice = "";
            for (int i = 0; i < N; i++) {
                slice += std::to_string(v[i][j]-48);
            }
            max += std::stoi(slice);
        }
    } else if (N < M) {
        max = 0;
        for (int i = 0; i < N; i++) {
            slice = "";
            for (int j = 0; j < M; j++) {
                slice += std::to_string(v[i][j]-48);
            }
            max += std::stoi(slice);
        }
    }
    */