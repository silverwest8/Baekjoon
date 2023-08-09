// 2023.8.8 18:14
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000

int N;
std::vector<int> v;

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    if (std::next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << -1;
    }

    return 0;
}
