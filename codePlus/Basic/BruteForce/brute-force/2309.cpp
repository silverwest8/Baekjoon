#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    int temp, i, j, k, sum;
    std::vector<int> v;
    for (i = 0; i < 9; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    std::sort(v.begin(), v.end());
    sum = std::accumulate(v.begin(), v.end(), 0);
    for (i = 0; i < 8; i++) {
        for (j = i+1; j < 9; j++) {
            if (v[i] + v[j] + 100 == sum) {
                for (k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        std::cout << v[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}