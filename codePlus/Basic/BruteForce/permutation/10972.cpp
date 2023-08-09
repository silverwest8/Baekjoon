// 2023.8.8 18:14 ... 23:38
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000

int N;
bool find = false;
std::vector<int> v;

int main(int argc, char* argv[]) {
    int temp, count;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
    }
    
    for(int i = N-1; i >= 1; i--) {
        if (v[i-1] < v[i]) {
            count = i;
            find = 1;
            break;
        }
    }

    if (find) {
        // v[count-1]+1 보다 크거나 같은 가장 작은 수
        for (int i = N-1; i >= count ; i--) {
            if (v[count-1] < v[i]) {
                std::swap(v[count-1], v[i]);
                break;
            }
        }
        std::sort(v.begin()+count, v.end());
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << -1;
    }
    return 0;
}
