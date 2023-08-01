#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char* argv[]) {
    int N, temp, count = 0;
    std::vector<int> v;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.push_back(temp);
    }
    for (int n: v) {
        for (int i = 2; i <= n; i++) {
            if (n%i == 0 && i != n) {
                break;
            }
            if (i == n) {
                count++;
            }
        }
    }

    std::cout << count;
    
    return 0;
}