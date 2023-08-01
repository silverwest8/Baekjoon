#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	int a = (int) sqrt(n);
	for (int i = 2; i <= a; i++) {
        if (n % i == 0) return false;
    }
	return true;
}

int minDivisor(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return i;
    }
}

int main(int argc, char* argv[]) {
    int N, minDiv;
    cin >> N;

    if (N == 1) return 0;

    while (!isPrime(N))
    {
        minDiv = minDivisor(N);
        cout << minDiv << endl;
        N /= minDiv;
    }
    cout << N << endl;
    
    return 0;
}