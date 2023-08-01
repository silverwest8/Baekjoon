#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int N = 9, max = 0, x=1, y=1;
    vector<vector<int>> matrix1(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix1[i][j];
            if (matrix1[i][j] > max) {
                max = matrix1[i][j];
                x = i+1;
                y = j+1;
            }
        }
    }
    
    cout << max << endl;
    cout << x << " " << y;

    return 0;
}