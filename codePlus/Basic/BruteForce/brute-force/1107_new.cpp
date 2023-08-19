#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ABS(x)        ( ((x)<0)?-(x):(x) )

int N, M, N_size, min, flag, check;
std::string N_string;
std::vector<int> ok, no, v;

void DFS(int n, int len) {
    if (n == len) {
        if (v[0] == 0 && v.size() > 1) return;
        int temp = 0;
        std::string temp_string = "";
        for (int i = 0; i < v.size(); i++) {
            temp_string += std::to_string(v[i]);
            temp++;
        }
        int sub = ABS(N - std::stoi(temp_string));
        temp += sub;
        if (temp < min) min = temp;
    } else {
        for (int i = 0; i < ok.size(); i++) {
            v.emplace_back(ok[i]);
            DFS(n+1, len);
            v.pop_back();
        }
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N_string >> M;
    N = std::stol(N_string);
    N_size = N_string.size();
    min = ABS(N-100);
    for (int i = 0; i < M; i++) {
        std::cin >> temp;
        no.emplace_back(temp);
    }
    for (int i = 0; i <= 9; i++) {
        if (std::find(no.begin(), no.end(), i) == no.end()) { // 쓸 수 있으면
            ok.emplace_back(i);
        }
    }
    if (N == 100) {
        std::cout << 0;
    } else {
        for (int i = 1; i <= N_size+1; i++) {
            DFS(0, i);
        }
        std::cout << min;
    }
    return 0;
}