#include <iostream>
#include <vector>
#define MAX 1000

std::vector<int> v(MAX+1);

int dp(int n) {
    v[1] = 1;
    v[2] = 3;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i-2]*2 + v[i-1])%10007;
    }
    return v[n];
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    std::cout << dp(n);
    return 0;
}