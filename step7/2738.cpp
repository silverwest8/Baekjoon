#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M, temp;
    cin >> N >> M;
    vector<vector<int>> matrix1(N);
    vector<vector<int>> matrix2(N);
    vector<vector<int>> matrix3(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            matrix1[i].push_back(temp);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            matrix2[i].push_back(temp);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix3[i].push_back(matrix1[i][j]+matrix2[i][j]);
            cout << matrix3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}