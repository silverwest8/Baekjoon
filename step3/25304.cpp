#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int X, N, a, b, n, T=0;
    cin >> X >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> n;
        T+=a*n;
    }
    if (X == T) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}