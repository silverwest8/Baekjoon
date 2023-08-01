#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    int N, temp, i, j;
    std::cin >> N;
    std::vector<int> v;
    for (i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            if (v[i] < v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for (i = 0; i < N; i++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}
