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
