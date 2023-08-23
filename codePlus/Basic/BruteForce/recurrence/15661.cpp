// https://www.acmicpc.net/problem/15661
// 링크와 스타트
// N명의 사람들을 팀 두개로 나누어 능력치 합의 차이의 최소값 구하기(팀당 인원수 1명 이상)

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20

int N, min;
std::vector<std::vector<int>> v(MAX+1, std::vector<int>(MAX+1));
std::vector<int> team;
std::vector<int> team2;

void DFS(int n, int next) {
    if (n >= 1 && n <= N-1) {
        int t1, t2;
        team2.clear();
        for (int i = 1; i <= N; i++) {
            if (std::find(team.begin(), team.end(), i) == team.end()) {
                team2.emplace_back(i);
            }
        }
        t1 = 0;
        for (int i = 0; i < team.size()-1; i++) {
            for (int j = i+1; j < team.size(); j++) {
                t1 += v[team[i]][team[j]]+v[team[j]][team[i]];
            }
        }
        t2 = 0;
        for (int i = 0; i < team2.size()-1; i++) {
            for (int j = i+1; j < team2.size(); j++) {
                t2 += v[team2[i]][team2[j]]+v[team2[j]][team2[i]];
            }
        }
        int sub = t1-t2;
        if (sub < 0) sub *= -1;
        if (min > sub) min = sub;
    }
    for (int i = next; i <= N ; i++) {
        team.emplace_back(i);
        DFS(n+1, i+1);
        team.pop_back();
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
    DFS(0, 1);
    std::cout << min;

    return 0;
}