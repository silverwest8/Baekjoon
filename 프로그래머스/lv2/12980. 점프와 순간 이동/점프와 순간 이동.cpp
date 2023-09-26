#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int N = n;
    int now = 0;
    // K칸 점프 -> K만큰 건전지 사용량
    // 현재거리*2 순간이동
    // 건전지 사용량의 최솟값

    while(N >= 0) {
        if (N == 1 || N == 2) {
            ans++;
            break;
        }
        if (N%2 == 0) {
            N /= 2;
        } else {
            N--;
            ans++;
        }
    }
    
    
    return ans;
}