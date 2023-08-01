#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return false;
    int a = (int)std::sqrt(n);
    for (int i = 2; i <= a; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int M, N;
    std::cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (isPrime(i)) std::cout << i << "\n";
    }
    
    return 0;
}