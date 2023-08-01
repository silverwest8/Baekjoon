#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    return a.first < b.first;
}

int main(int argc, char* argv[]) {

    int N, temp, i;
    std::vector<std::pair<int, std::string>> v;
    std::string s;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> temp >> s;
        v.emplace_back(std::make_pair(temp, s));
    }
    std::stable_sort(v.begin(), v.end(), compare);

    for (i = 0; i < v.size(); i++) {
        std::cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
