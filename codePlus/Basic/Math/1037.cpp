#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int n, i, temp;
    std::vector<int> v;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    std::sort(v.begin(), v.end());

    std::cout << v[0]*v[v.size()-1];
    


    return 0;
}
