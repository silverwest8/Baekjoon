#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    int N, x, y, i, j;
    std::vector<std::string> v;
    std::string s;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> s;
        v.emplace_back(s);
    }
    sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(),v.end()),v.end());

    for (j = 1; j <= 50; j++) {
        for (i = 0; i < v.size(); i++) {
            if (v[i].size() == j) {
                std::cout << v[i] << "\n";
            }
        }
    }

    return 0;
}
