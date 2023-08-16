#include <iostream>
#include <vector>
#define MAX 300

int N, M;
std::vector<std::vector<int>> v(MAX, std::vector<int>(MAX));
// std::vector<std::vector<int>> v2(MAX, std::vector<int>(MAX));

// 시간초과남
/*
void copyArr(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            b[i][j] = a[i][j];
        }
    }
}
*/

void printArr(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void rotate(int k, int num) {
    for (int l = 0; l < num; l++) {
        // std::copy(v.begin(), v.end(), v2.begin());
        // copyArr(v, v2);
        /*
        for (int j = k+1; j < M-k; j++) { // <-
            v2[k][j-1] = v[k][j];
        }
        for (int i = k; i < N-k-1; i++) {
            v2[i+1][k] = v[i][k];
        }
        for (int j = k; j < M-k-1; j++) { // ->
            v2[N-k-1][j+1] = v[N-k-1][j];
        }
        for (int i = k+1; i < N-k; i++) {
            v2[i-1][M-k-1] = v[i][M-k-1];
        }
        */

        // v2 안쓰고 내부에서 옮기기
        int save1 = v[k][k], save2 = v[k][M-k-1], save3 = v[N-k-1][k], save4 = v[N-k-1][M-k-1];
        for (int j = k; j < M-k-1; j++) { // <-
            v[k][j] = v[k][j+1];
        }

        for (int i = N-k-1; i >= k+2; i--) { // 아래로
            v[i][k] = v[i-1][k];
        }
        v[k+1][k] = save1;

        for (int j = M-k-1; j >= k+2; j--) { // ->
            v[N-k-1][j] = v[N-k-1][j-1];
        }
        v[N-k-1][k+1] = save3;

        for (int i = k; i < N-k-2; i++) { // 위로
            v[i][M-k-1] = v[i+1][M-k-1];
        }
        v[N-k-2][M-k-1] = save4;
        /*
        std::copy(v2.begin(), v2.end(), v.begin());
        copyArr(v2, v);
        --- //
        for (int j = k; j < M-k; j++) { // <-
            v[k][j] = v2[k][j];
        }
        for (int i = k; i < N-k; i++) {
            v[i][k] = v2[i][k];
        }
        for (int j = k; j < M-k; j++) { // ->
            v[N-k-1][j] = v2[N-k-1][j];
        }
        for (int i = k; i < N-k; i++) {
            v[i][M-k-1] = v2[i][M-k-1];
        }
        */
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int R, temp;
    std::cin >> N >> M >> R;
        std::vector<int> vec;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> temp;
            v[i][j] = temp;
        }
    }
    /*
    for (int l = 0; l < R; l++) {
        for (int k = 0; k < std::min(N, M)/2; k++) {
            rotate(k);
        }
        std::copy(v2.begin(), v2.end(), v.begin());
        std::fill(v2.begin(), v2.end(), std::vector<int>(M));
    }
    */
    int len;
    for (int i = 0; i < std::min(N, M)/2; i++) {
        len = R % (2*(N-(2*i))+2*(M-(2*i))-4);
        rotate(i, len);
    }
    // std::copy(v2.begin(), v2.end(), v.begin());

    printArr(N, M);
    return 0;
}
