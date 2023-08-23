// https://www.acmicpc.net/problem/14889
// 스타트와 링크
// 짝수 N명의 사람들을 N/2명의 팀 두개로 나눌 때 능력치 차이의 최소값 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20

int N, t1, t2, sum1, sum2, min;
std::vector<std::vector<int>> v(MAX+1, std::vector<int>(MAX+1));
std::vector<int> team;

void DFS(int n, int start) {
    if (n == N/2) {
        t1 = t2 = sum1 = sum2 = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // vector 내에 포함하는지
                if (std::find(team.begin(), team.end(), i) != team.end() && std::find(team.begin(), team.end(), j) != team.end()) {
                    sum1+=v[i][j];
                }
                if (std::find(team.begin(), team.end(), i) == team.end() && std::find(team.begin(), team.end(), j) == team.end()) {
                    sum2+=v[i][j];
                }
            }
        }
        int temp = sum1 - sum2;
        if (temp < 0) temp = 0-temp;
        if (temp < min) min = temp;
        return;
    } else {
        for (int i = start; i <= N; i++) {
            // 그냥 true, false로도 체크 가능
            team.emplace_back(i);
            DFS(n+1, i+1);
            team.pop_back();
        }
    }
}

int main(int argc, char* argv[]) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> v[i][j];
            min+=v[i][j];
        }
    }
    // N명 중에 2/N명을 뽑아야 함
    DFS(0, 1);
    std::cout << min;

    return 0;
}