#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {

    int N, first, temp, i, j;
    std::vector<int> v, w;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        w.emplace_back(temp);
        v.emplace_back(temp);
    }

    // vector 중복 제거 -> sorting 이후
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(),v.end()),v.end());
    
    for (i = 0; i < w.size(); i++) {
        // c++에서는 이진 탐색으로 원소를 탐색하는 lower_bound, upper_bound
        // 정렬되어있어야 하고, value보다 작지 않은 첫번째 원소 return, 없으면 last return
        std::cout << std::lower_bound(v.begin(), v.end(), w[i])-v.begin() << " ";
    }

    return 0;
}
