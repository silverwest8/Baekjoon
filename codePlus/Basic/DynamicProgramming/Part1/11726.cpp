#include <iostream>
#define max 1000

int N;
int arr[max+1];

int way(int n) {
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }
    return arr[n];
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    std::cout << way(N);
    return 0;
}