#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = i; j <= n; j++) {
            count+=j;
            if (count == n) {
                answer++;
                break;
            } else if (count > n) {
                break;
            }
        }
    }
    return answer;
}