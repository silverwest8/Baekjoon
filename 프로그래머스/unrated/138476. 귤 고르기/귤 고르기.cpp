#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int K;
int answer = 10000000;
std::vector<int> v(10000000+1, 0);
std::vector<bool> visited(10000000+1, false);
std::vector<int> v2(0);

void dfs(int n, int sum) {
    if (sum >= K) {
        // int i = 0;
        // while(i < v2.size()) {
        //     if (v2[i]) {
        //         std::cout << v2[i] << " ";
        //     } else {
        //         break;
        //     }
        //     i++;
        // }
        // std::cout << "\n";
        if (answer > n) answer = n;
        return;
    }
    int i = 0;
    while(v[i] != 0 && !visited[i]) {
        visited[i] = true;
        v2.emplace_back(v[i]);
        dfs(n+1, sum+v[i]);
        v2.pop_back();
        visited[i] = false;
        i++;
    }
}

int solution(int k, vector<int> tangerine) {
    K = k;
    // std::vector<std::vector<int>> v;
    // std::sort(tangerine.begin(), tangerine.end());
    // int before = 0;
    for (int i = 0; i < tangerine.size(); i++) {
        v[tangerine[i]]++;
        // before = tangerine[i];
        // v.emplace_back(std::vector<int>());
    }
    std::sort(v.begin(), v.end(), std::greater<>());
    
    int j = 0;
    while(true) {
        if (v[j]) {
            std::cout << v[j] << " ";
        } else {
            break;
        }
        j++;
    }
    std::cout << "\n";
    // dfs(0, 0);
    
    int i = 0;
    int sum = 0;
    while(true) {
        if (v[i] != 0) {
            sum+=v[i];
            if (sum >= K) {
                answer = i+1;
                break;
            }
        } else {
            break;
        }
        i++;
    }
    std::cout << "\n";
    
    return answer;
}