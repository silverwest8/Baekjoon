#include <iostream>
#include <vector>
#define max 1000000

int dp(int n) {
    std::vector<int> v(max+1);
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;
    for (int i = 4; i <= n; i++) {
        v[i] = v[i-1] + 1;
        if (i%2==0) v[i] = std::min(v[i], v[i/2]+1);
        if (i%3==0) v[i] = std::min(v[i], v[i/3]+1);
    }
    return v[n];
}

int DP(int n) {
    std::vector<int> v(max+1);
    for (int i = 0; i <= max; i++) {
        v[i] = i-1;
    }

    for (int i = 1; i <= n; i++) {
        if (i*3 <= n) {
            v[i*3] = std::min(v[i*3], v[i]+1);
        }
        if (i*2 <= n) {
            v[i*2] = std::min(v[i*2], v[i]+1);
        }
        if (i+1 <= n) {
            v[i+1] = std::min(v[i+1], v[i]+1);
        }
    }
    return v[n];
}

int cal(int n) {
    std::vector<int> v(max+1);
    for (int i = 0; i <= max; i++) {
        v[i] = i-1;
    }

    for (int i = 1; i <= n; i++) {
        if (i*3 <= n && v[i*3] > v[i]+1) {
            v[i*3] = v[i]+1;
        }
        if (i*2 <= n && v[i*2] > v[i]+1) {
            v[i*2] = v[i]+1;
        }
        if (i+1 <= n && v[i+1] > v[i]+1) {
            v[i+1] = v[i]+1;
        }
    }
    return v[n];
}

int main(int argc, char* argv[]) {
    
    int N;
    std::cin >> N;
    // std::cout << cal(N);
    // std::cout << DP(N);
    std::cout << dp(N);

    return 0;
}