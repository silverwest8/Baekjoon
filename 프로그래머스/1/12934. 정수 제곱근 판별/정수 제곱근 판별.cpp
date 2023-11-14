#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    double d = sqrt(n);
    long long l = (long long)d;
    if (d == (double)l) {
        answer = (d+1)*(d+1);
    }
    return answer;
} 