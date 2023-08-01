#include <iostream>

using namespace std;

int f(int a1, int a0, int n) {
    return a1*n + a0;
}
int g(int n) {
    return n;
}

int main(int argc, char* argv[]) {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    for (int n = n0; n <= 100; n++) {
        if (f(a1, a0, n) > c*g(n)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}