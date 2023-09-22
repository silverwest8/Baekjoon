#include <string>
#include <vector>
#define MAX 100000
using namespace std;
int arr[MAX+1];

int dp(int n) {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i-1]+arr[i-2])%1234567;
    }
    return arr[n];
}

int solution(int n) {
    int answer = dp(n);
    return answer;
}