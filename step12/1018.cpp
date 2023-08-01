#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M, c1=0, c2=0, min=64;
    string temp;
    cin >> N >> M;

    vector<string> v;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i <= N-8; i++) {
        for (int j = 0; j <= M-8; j++) {

            for (int x = i; x < i+8; x++) {
                for (int y = j; y < j+8; y++) {
                    if (x%2==0) { // 짝 (0, 2, ...)
                        if (y%2==0) {
                            if (v[x][y] != 'W') c1++;
                            if (v[x][y] != 'B') c2++;
                        } else {
                            if (v[x][y] != 'B') c1++;
                            if (v[x][y] != 'W') c2++;
                        }
                    } else { // 홀 (1, 3, ...)
                        if (y%2==0) {
                            if (v[x][y] != 'B') c1++;
                            if (v[x][y] != 'W') c2++;
                        } else {
                            if (v[x][y] != 'W') c1++;
                            if (v[x][y] != 'B') c2++;
                        }
                    }
                }
            }

            if (c1 < min) min = c1;
            if (c2 < min) min = c2;
            c1 = 0;
            c2 = 0;
        }
    }

    cout << min;

    return 0;
}
