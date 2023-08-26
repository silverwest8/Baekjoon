// https://www.acmicpc.net/problem/10971
// 순회 여행 경로 구하기 -> 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 돌아올 때 드는 최소비용 구하기
// DFS 사용 - 몇번째 숫자인지 구별해서 넣기

#include <iostream>
#define MAX 10

int N, min;
int map[MAX][MAX];
int way[MAX+1];
bool visited[MAX];

void DFS(int n, int sum) {
    if (n == N+1) {
        if (sum < min) min = sum;
        return;
    }
    if (n == 0) {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                way[n] = i;
                DFS(n+1, sum);
                way[n] = 0;
                visited[i] = false;
            }
        }
    } else if (n != N) {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                way[n] = i;
                if (map[way[n-1]][way[n]]) {
                    DFS(n+1, sum+map[way[n-1]][way[n]]);
                }
                way[n] = 0;
                visited[i] = false;
            }
        }
    } else if (n == N) {
        way[n] = way[0];
        if (map[way[n-1]][way[n]]) {
            DFS(n+1, sum+map[way[n-1]][way[n]]);
        }
        way[n] = 0;
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio;
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            min += map[i][j];
        }
    }
    DFS(0, 0);
    std::cout << min;
    return 0;
}