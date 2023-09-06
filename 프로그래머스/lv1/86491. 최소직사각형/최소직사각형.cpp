#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;
int min_ = 1000000;
std::vector<int> v;
/*
void DFS(int n, int max1, int max2, vector<vector<int>> &sizes) {
    if (n == N) {
        int temp = max1*max2;
        if (min_ > temp) min_ = temp;
        return;
    }
    for (int i = 0; i < 2; i++) {
        v.emplace_back(i);
        DFS(n+1, std::max(sizes[n][i], max1), std::max(sizes[n][!i], max2), sizes);
        v.pop_back();
    }
}
*/

int solution(vector<vector<int>> sizes) {
    // N = sizes.size();
    if (sizes[0][0] < sizes[0][1]) {
        std::swap(sizes[0][0], sizes[0][1]);
    }
    int max1 = sizes[0][0], max2 = sizes[0][1];
    for (int i = 1; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            std::swap(sizes[i][0], sizes[i][1]);
        }
        if (max1 < sizes[i][0]) max1 = sizes[i][0];
        if (max2 < sizes[i][1]) max2 = sizes[i][1];        
        
    }
    // v.emplace_back(0);
    // DFS(1, sizes[0][0], sizes[0][1], sizes);
    
    return max1*max2;
}