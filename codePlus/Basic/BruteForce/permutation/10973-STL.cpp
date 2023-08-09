#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int N, temp;
    std::vector<int> v;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    if (std::prev_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << -1;
    }
    return 0;
}