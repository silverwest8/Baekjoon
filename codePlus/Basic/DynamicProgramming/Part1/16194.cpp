#include <iostream>
#include <vector>
#define MAX 1000

int N;
std::vector<int> v(MAX+1);
std::vector<int> v2(MAX+1);

int DP(int n) {
    v2[1] = v[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            v2[i] = std::min(v2[i-j]+v2[j], v2[i]);
        }
    }
    return v2[n];
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> v[i];
        v2[i] =  v[i];
    }
    std::cout << DP(N);
    return 0;
}