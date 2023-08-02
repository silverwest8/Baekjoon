#include <iostream>
#include <vector>
#include <algorithm>

void printArr(std::vector<std::vector<int>> v, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    int N, M, R, temp, i, j, k;
    std::cin >> N >> M >> R;
    std::vector<int> cal(1000);
    std::vector<std::vector<int>> v(100, std::vector<int>(100));
    std::vector<std::vector<int>> v2(100, std::vector<int>(100));
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            std::cin >> temp;
            v[i][j] = temp;
        }
    }
    for (i = 0; i < R; i++) {
        std::cin >> temp;
        cal[i] = temp;
    }

    for (k = 0; k < R; k++) {
        switch (cal[k])
        {
        case 1:
            // 상하
            for (i = 0; i < N/2; i++) {
                for (j = 0; j < M; j++) {
                    std::swap(v[i][j], v[N-i-1][j]);
                }
            }
            break;
        case 2:
            // 좌우
            for (j = 0; j < M/2; j++) {
                for (i = 0; i < N; i++) {
                    std::swap(v[i][j], v[i][M-j-1]);
                }
            }
            break;
        case 3:
            // 오른쪽 90도
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    v2[j][N-1-i] = v[i][j];
                }
            }
            std::copy(v2.begin(), v2.end(), v.begin());
            std::swap(N, M);
            break;
        case 4:
            // 왼쪽 90도
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    v2[M-1-j][i] = v[i][j];
                }
            }
            std::copy(v2.begin(), v2.end(), v.begin());
            std::swap(N, M);
            break;
        case 5:
            // 1->2, 2->3, 3->4, 4->1
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (i < N/2 && j < M/2) v2[i][j+M/2] = v[i][j]; // 1->2
                    if (i < N/2 && j >= M/2) v2[i+N/2][j] = v[i][j]; // 2->3
                    if (i >= N/2 && j >= M/2) v2[i][j-M/2] = v[i][j]; // 3->4
                    if (i >= N/2 && j < M/2) v2[i-N/2][j] = v[i][j]; // 4->1
                }
            }
            std::copy(v2.begin(), v2.end(), v.begin());
            break;
        case 6:
            // 1->4, 4->3, 3->2, 2->1
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (i < N/2 && j < M/2) v2[i+N/2][j] = v[i][j]; //  1->4
                    if (i >= N/2 && j < M/2) v2[i][j+M/2] = v[i][j]; // 4->3
                    if (i >= N/2 && j >= M/2) v2[i-N/2][j] = v[i][j]; // 3->2
                    if (i < N/2 && j >= M/2) v2[i][j-M/2] = v[i][j]; // 2->1
                }
            }
            std::copy(v2.begin(), v2.end(), v.begin());
            break;
        default:
            break;
        }
    }
    printArr(v, N, M);
    return 0;
}

/*

void printArr(std::vector<std::vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    int N, M, R, temp, i, j, k;
    std::cin >> N >> M >> R;
    std::vector<int> cal;
    std::vector<std::vector<int>> v;
    std::vector<std::vector<int>> v2;
    std::vector<std::vector<int>> v3;
    for (i = 0; i < N; i++) {
        v.emplace_back(std::vector<int>());
        for (j = 0; j < M; j++) {
            std::cin >> temp;
            v[i].emplace_back(temp);
        }
    }
    for (i = 0; i < R; i++) {
        std::cin >> temp;
        cal.emplace_back(temp);
    }

    for (k = 0; k < R; k++) {
        switch (cal[k])
        {
        case 1:
            // 상하
            for (i = 0; i < v.size()/2; i++) {
                for (j = 0; j < v[0].size(); j++) {
                    std::swap(v[i][j], v[v.size()-i-1][j]);
                }
            }
            break;
        case 2:
            // 좌우
            for (i = 0; i < v.size(); i++) {
                std::reverse(v[i].begin(), v[i].end());
            }
            break;
        case 3:
            // 오른쪽 90도
            v2.clear();
            v2.resize(v[0].size(), std::vector<int>(v.size()));
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j < v[0].size(); j++) {
                    v2[j][v.size()-1-i] = v[i][j];
                }
            }
            v.clear();
            v.assign(v2.size(), std::vector<int>(v2[0].size()));
            std::copy(v2.begin(), v2.end(), v.begin());
            break;
        case 4:
            // 왼쪽 90도
            v2.clear();
            v2.resize(v[0].size(), std::vector<int>(v.size()));
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j < v[0].size(); j++) {
                    v2[v[0].size()-1-j][i] = v[i][j];
                }
            }
            v.clear();
            v.assign(v2.size(), std::vector<int>(v2[0].size()));
            std::copy(v2.begin(), v2.end(), v.begin());
            break;
        case 5:
            v3.resize(v.size(), std::vector<int>(v[0].size()));
            // 1->2, 2->3, 3->4, 4->1
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j < v[0].size(); j++) {
                    if (i < v.size()/2 && j < v[0].size()/2) v3[i][j+v[0].size()/2] = v[i][j]; // 1->2
                    if (i < v.size()/2 && j >= v[0].size()/2) v3[i+v.size()/2][j] = v[i][j]; // 2->3
                    if (i >= v.size()/2 && j >= v[0].size()/2) v3[i][j-v[0].size()/2] = v[i][j]; // 3->4
                    if (i >= v.size()/2 && j < v[0].size()/2) v3[i-v.size()/2][j] = v[i][j]; // 4->1
                }
            }
            std::copy(v3.begin(), v3.end(), v.begin());
            break;
        case 6:
            v3.resize(v.size(), std::vector<int>(v[0].size()));
            // 1->4, 4->3, 3->2, 2->1
            for (i = 0; i < v.size(); i++) {
                for (j = 0; j < v[0].size(); j++) {
                    if (i < v.size()/2 && j < v[0].size()/2) v3[i+v.size()/2][j] = v[i][j]; //  1->4
                    if (i >= v.size()/2 && j < v[0].size()/2) v3[i][j+v[0].size()/2] = v[i][j]; // 4->3
                    if (i >= v.size()/2 && j >= v[0].size()/2) v3[i-v.size()/2][j] = v[i][j]; // 3->2
                    if (i < v.size()/2 && j >= v[0].size()/2) v3[i][j-v[0].size()/2] = v[i][j]; // 2->1
                }
            }
            std::copy(v3.begin(), v3.end(), v.begin());
            break;
        default:
            break;
        }
    }
    printArr(v);
    return 0;
}

*/