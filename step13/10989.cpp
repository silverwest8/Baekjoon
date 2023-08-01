#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    // 실행 시간 단축
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    int N, temp, i, j;
    int arr[10001] = {0, };
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        arr[temp]++;
    }

    for (i = 1; i < 10001; i++) {
        for (j = 0; j < arr[i]; j++) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
