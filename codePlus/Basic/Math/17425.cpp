#include <iostream>
#define max 1000000

int main(int argc, char* argv[]) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, T, i, j;
    long arr[max+1] = {0, };
    long result = 0;

    for (i = 1; i <= max; i++) {
        for (j = i; j <= max; j+=i) {
            arr[j] += i;
        }
        arr[i] += arr[i-1];
    }

    std::cin >> T;
    for (i = 0; i < T; i++) {
        std::cin >> N;
        std::cout << arr[N] << "\n";
    }

    return 0;
}
