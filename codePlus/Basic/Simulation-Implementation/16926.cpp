#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> v(300, std::vector<int>(300));
std::vector<std::vector<int>> v2(300, std::vector<int>(300));

void printArr(std::vector<std::vector<int>> v, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// 3중 for문을 돌릴 필요가 없었음! 시간초과 주의
void rotate(std::vector<std::vector<int>> &v, int N, int M) {
    for (int k = 0; k < std::min(N, M)/2; k++) {
        for (int j = k+1; j < M-k; j++) {
            v2[k][j-1] = v[k][j];
        }
        for (int i = k; i < N-k-1; i++) {
            v2[i+1][k] = v[i][k];
        }
        for (int j = k; j < M-k-1; j++) {
            v2[N-k-1][j+1] = v[N-k-1][j];
        }
        for (int i = k+1; i < N-k; i++) {
            v2[i-1][M-k-1] = v[i][M-k-1];
        }
    }
    std::copy(v2.begin(), v2.end(), v.begin());
    std::fill(v2.begin(), v2.end(), std::vector<int>(M));
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int R, temp;
    std::cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> temp;
            v[i][j] = temp;
        }
    }
    
    for (int l = 0; l < R; l++) {
        rotate(v, N, M);
    }
    printArr(v, N, M);
    return 0;
}