#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, N = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        N+=i;
    }
    cout << N;
    return 0;
}