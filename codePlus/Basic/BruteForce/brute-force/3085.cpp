#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    int N, i, j, k, a, b, count = 0, max = 0;
    std::string s;
    char base, now;
    std::vector<std::vector<char>> v;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        v.emplace_back(std::vector<char>());
        std::cin >> s;
        for (j = 0; j < N; j++) {
            v[i].emplace_back(s[j]);
        }
    }
    
    // 좌우로 바꾸기
    for (i = 0; i < N; i++) {
        for (j = 0; j < N-1; j++) {
            std::swap(v[i][j], v[i][j+1]);
            // 행
            for (k = 0; k < N; k++) {
                count = 0;
                base = v[k][0];
                for (a = 0; a < N; a++) {
                    if (base == v[k][a]) count++;
                    else count = 1;
                    base = v[k][a];
                    if (max < count) max = count;
                }
            }
            // 열
            for (k = 0; k < N; k++) {
                count = 0;
                base = v[0][k];
                for (a = 0; a < N; a++) {
                    if (base == v[a][k]) count++;
                    else count = 1;
                    base = v[a][k];
                    if (max < count) max = count;
                }
            }
            std::swap(v[i][j], v[i][j+1]);
        }
    }

    // 상하로 바꾸기
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N; j++) {
            std::swap(v[i][j], v[i+1][j]);
            // 행
            for (k = 0; k < N; k++) {
                count = 0;
                base = v[k][0];
                for (a = 0; a < N; a++) {
                    if (base == v[k][a]) count++;
                    else count = 1;
                    base = v[k][a];
                    if (max < count) max = count;
                }
            }
            // 열
            for (k = 0; k < N; k++) {
                count = 0;
                base = v[0][k];
                for (a = 0; a < N; a++) {
                    if (base == v[a][k]) count++;
                    else count = 1;
                    base = v[a][k];
                    if (max < count) max = count;
                }
            }
            std::swap(v[i][j], v[i+1][j]);
        }
    }

    std::cout << max;

    return 0;
}

/*

5
YCCYC
CYCCP
PZPYP
ZZPZZ
YPPCZ

*/