#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round = 1;
    while(a != b) {
        a = (a+1)/2;
        b = (b+1)/2;
        round++;
    }
    answer = round-1;
    //  1   2   3   4
    // 1 2 3 4 5 6 7 8

    return answer;
}