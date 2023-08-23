// https://www.acmicpc.net/problem/2529
// 2 <= K <= 9개의 부등호를 만족시키는 각자리가 서로 다른 숫자인 K+1 자리의 최대, 최소 숫자 출력
// int 범위 초과 주의 -> long 사용
// 맨 앞자리 0 주의 -> min, max 갱신 시 string 값도 update
// 모든 경우 탐색 위해 DFS 이용, 재귀 조건 : <일때와 >일때 조건 판별하여 탐색, 중복 불가이므로 visited 사용

#include <iostream>
#include <vector>
#include <string>

int K;
long min = 9999999999, max = 0;
std::string min_string, max_string;
std::vector<char> v;
std::vector<bool> visited(9, false);

void DFS(int n) {
    if (n == K+1) {
        std::string temp = "";
        long temp2 = 0;
        for (int i = 0; i < K+1; i++) {
            temp += std::to_string(v[i*2]);
        }
        temp2 = std::stoull(temp);
        if (temp2 < min) {
            min = temp2;
            min_string = temp;
        }
        if (temp2 > max) {
            max = temp2;
            max_string = temp;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (n == 0 || (v[n*2-1] == '<' && v[2*(n-1)] < i) || (v[n*2-1] == '>' && v[2*(n-1)] > i)) {
            if (!visited[i]) {
                visited[i] = true;
                v[n*2] = i;
                DFS(n+1);
                visited[i] = false;
            }
        }
    }
}
int main(int argc, char* argv[]) {
    char temp;
    std:: cin >> K;
    v.emplace_back(0);
    for (int i = 0; i < K; i++) {
        std::cin >> temp;
        v.emplace_back(temp);
        v.emplace_back(0);
    }

    DFS(0);

    std::cout << max_string << "\n";
    std::cout << min_string << "\n";
    return 0;
}