#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int save = x;
    int count = 0;
    while (count < n) {
        answer.emplace_back(x);
        x+=save;
        count++;
    }
    return answer;
}