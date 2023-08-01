#include <iostream>
#define max 1000000

int main(int argc, char* argv[]) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, find;
    int arr[max+1] = {0, };
    for (int i = 0; i <= max; i++) {
        arr[i] = i;
    }
    for (int i = 2; i*i <= max; i+=2) {
        if (arr[i] == 0) continue;
        for (int j = 2; i*j <= max; j++) {
            arr[i*j] = 0;
        }
    }

    while(true) {
        find = 0;
        std::cin >> n;
        if (!n) break;

        for (int i = 3; i*i <= max ; i++) {
            if (arr[i] == 0 || arr[n-i] == 0) continue;
            find = 1;
            std::cout << n << " = " << i << " + " << n-i << "\n";
            break;
        }
        if (!find) std::cout << "Goldbach's conjecture is wrong." << "\n";
    }
    return 0;
}

/*
bool isPrime(int n) {
    if (n < 2) return false;
    int a = (int)std::sqrt(n);
    for (int i = 2; i <= a; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n, a, b, find = 0;
    while(true) {
        find = 0;
        std::cin >> n;
        if (!n) break;

        for (int i = 3; i <= n/2; i++) {
            a = i;
            b = n - i;
            if (isPrime(a) && isPrime(b)) {
                find = 1;
                break;
            }
        }

        if (find) {
            std::cout << n << " = " << a << " + " << b << "\n";
        } else {
            std::cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }
    
    return 0;
}

*/