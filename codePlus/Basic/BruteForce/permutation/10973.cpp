// 2023.8.9 23:38 - 2023.8.10. 00:00
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int N, temp, count;
    bool find = false;
    std::vector<int> v;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    for (int i = N-1; i >= 1; i--) {
        if (v[i-1] > v[i]) {
            count = i;
            find = 1;
            break;
        }
    }
    if (find) {
        for (int i = N-1; i >= count; i--) {
            if (v[count-1] > v[i]) {
                std::swap(v[count-1], v[i]);
                break;
            }
        }
        std::sort(v.begin()+count, v.end(), std::greater<>());
        for (int i = 0; i < N; i++) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << -1;
    }
    return 0;
}