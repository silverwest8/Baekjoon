#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int N, k, x, temp, i;
    std::vector<int> v;
    std::cin >> N >> k;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    std::sort(v.begin(), v.end(), std::greater<>());

    std::cout << v[k-1];

    return 0;
}
