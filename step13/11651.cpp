#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    int N, x, y, i, j;
    std::vector<std::pair<int, int>> v;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> x >> y;
        v.emplace_back(std::pair(y, x));
    }
    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++) {
        std::cout << v[i].second << " " << v[i].first << "\n";
    }

    return 0;
}
