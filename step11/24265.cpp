#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    long long int n, cnt = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << 2;
    return 0;
}