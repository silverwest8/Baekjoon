#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    int N=5, temp, i, j;
    std::vector<int> v;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    std::sort(v.begin(), v.end());

    std::cout << std::accumulate(v.begin(), v.end(), 0)/N << std::endl;
    std::cout << v[2];

    return 0;
}
