#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 소수판별
bool isPrime(int n) {
	if (n < 2) return false;
	int a = (int) sqrt(n);
	for (int i = 2; i <= a; i++) {
        if (n % i == 0) return false;
    }
	return true;
}

int main(int argc, char* argv[]) {
    int M, N, total = 0, min = 0;
    cin >> M >> N;
    min = N;
    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            total += i;
            if (i < min) min = i;
        }
    }

    if (total) {
        cout << total << "\n" << min;
    } else {
        cout << -1;
    }
    return 0;
}