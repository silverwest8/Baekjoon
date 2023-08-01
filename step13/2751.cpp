#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int N, k, x, temp, i;
    std::vector<int> v;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    std::sort(v.begin(), v.end());

    for (i = 0; i < N; i++) {
        std::cout << v[i] << "\n";
    }

    return 0;
}
