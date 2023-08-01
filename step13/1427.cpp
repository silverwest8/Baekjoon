#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char* argv[]) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    int N, temp, i, j;
    std::string s;
    std::vector<int> v;
    std::cin >> N;
    s = std::to_string(N);
    for (i = 0; i < s.size(); i++) {
        v.emplace_back(s[i]-48);
    }
    sort(v.begin(), v.end(), std::greater<>());

    for (i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }

    return 0;
}
