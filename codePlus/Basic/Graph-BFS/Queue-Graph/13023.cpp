#include <iostream>
// #include <algorithm>
#include <vector>
#define MAX 2000

int N, M, n1, n2;
bool find = false;
std::vector<std::vector<int>> v(MAX);
std::vector<bool> visited(MAX);
std::vector<int> v2;
// std::vector<int> check;
// std::vector<int> check2;
// std::vector<std::pair<int, int>> check3;


/*
void DFS(int n) {
    if (find) return;
    else if (n == 4) {
        check.clear();
        check2.clear();
        check3.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                check.emplace_back(v2[i][j]);
                check2.emplace_back(v2[i][j]);
            }
        }

        std::sort(check.begin(), check.end());
        check.erase(std::unique(check.begin(), check.end()), check.end());

        // for (int i = 0; i < check.size(); i++) {
        //     std::cout << check[i] << " ";
        // }
        // std::cout << "\n";

        if (check.size() != 5) {
            return;
        } else {
            for (int i = 0; i < check.size(); i++) {
                check3.emplace_back(check[i], 0);
            }
            for (int i = 0; i < check2.size(); i++) {
                for (int j = 0; j < check3.size(); j++) {
                    if (check2[i] == check3[j].first) check3[j].second++;
                }
            }
            n1 = n2 = 0;
            for (int i = 0; i < check3.size(); i++) {
                if (check3[i].second == 1) {
                    n1++;
                } else if (check3[i].second == 2) {
                    n2++;
                }
            }
            if (n1 == 2 && n2 == 3) find = true;
        }
    } else {
        for (int i = 0; i < M; i++) {
            if (!visited[i]) {
                visited[i] = true;
                v2.emplace_back(v[i]);
                DFS(n+1);
                v2.pop_back();
                visited[i] = false;
            }
        }
    }

}
*/

// void DFS(int start, int depth) {
//     if (depth == 5) {
//         find = true;
//         return;
//     } else {
//         visited[start] = true;
//         for (int i = 0; i < v[start].size(); i++) {
//             if (visited[v[start][i]] == true) continue;
//             DFS(v[start][i], depth + 1);
//             if (find == true) return;
//         }
//         visited[start] = false;
//     }
// }
 
void DFS(int n, int start) {
    // 이미 찾았으면 더 탐색할 필요 X
    if (!find) {
        // 친구관계 길이가 4인지 확인
        if (n == 4) {
            find = 1;
        } else {
            for (int i = 0; i < v[start].size(); i++) {
                int now = v[start][i];
                if (!visited[now]) {
                    visited[now] = true;
                    v2.emplace_back(now);
                    DFS(n+1, now);
                    v2.pop_back();
                    visited[now] = false;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int a, b;
    std::cin >> N >> M;

    // 입력 시 그래프 이용이 핵심!!
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    for (int i = 0; i < N; i++) {
        std::fill(visited.begin(), visited.end(), 0);
        visited[i] = true;
        v2.emplace_back(i);
        DFS(0, i);
        v2.pop_back();
        if (find) break;
    }
    std::cout << find;
    return 0;
}