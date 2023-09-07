#include <string>
#include <vector>

using namespace std;

int N;
int count = 0;
// std::vector<int> v;

void DFS(int n, int now, int target, vector<int> &numbers) {
    if (n == N) {
        if (now == target) {
            count++;
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        // v.emplace_back(i);
        if (i == 0) {
            DFS(n+1, now-numbers[n], target, numbers);
        } else {
            DFS(n+1, now+numbers[n], target, numbers);
        }
        // v.pop_back();
    }
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    DFS(0, 0, target, numbers);
    return count;
}