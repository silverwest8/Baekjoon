#include <iostream>
#include <vector>

int N, max = 0;
std::vector<std::vector<int>> v;
std::vector<int> v2;

// 내가 짠 DFS는 ㄹㅇ 모든 경우를 다 돌고 일일이 경우의 수 체크
void DFS(int depth, int start, int select) {
    if (depth == select) {

        for (int i = 0; i < v2.size()-1; i++) {
            if (v2[i] + v[v2[i]][0] > v2[i+1]) {
                return;
            }
        }
        if (v2[v2.size()-1] + v[v2[v2.size()-1]][0] > N) {
            return;
        }

        int sum = 0;
        for (int i = 0; i < v2.size(); i++) {
            sum += v[v2[i]][1];
        }
        if (max < sum) max = sum;

        // for (int i = 0; i < v2.size(); i++) {
        //     std::cout << v2[i] << " ";
        // }
        // std::cout << "\n";
    } else {
        for (int i = start; i < N; i++) {
            v2.emplace_back(i);
            DFS(depth+1, i+1, select);
            v2.pop_back();
        }
    }
}

// 몇개 골랐느냐와 상관 없이 start가 N에 딱 맞게 안끝나고 넘어버리면 종료됨
// dfs 할때마다 고른 날과 합을 넘겨주고 그때그때 계산(굳이 모든 경로를 저장할 필요 없이 max일때만 갱신)
void dfs(int start, int sum) {
    if (start > N) return;
    max = std::max(sum, max);
    for (int i = start; i < N; i++) {
        dfs(i+v[i][0], sum+v[i][1]);
    }
}

int main(int argc, char* argv[]) {
    int temp;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        v.emplace_back(std::vector<int>());
        for (int j = 0; j < 2; j++) {
            std::cin >> temp;
            v[i].emplace_back(temp);
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     DFS(0, 0, i);
    // }
    dfs(0, 0);
    std::cout << max;
    return 0;
}