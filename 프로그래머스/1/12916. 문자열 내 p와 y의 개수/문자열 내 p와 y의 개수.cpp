#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count = 0, count2 = 0;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            count++;
        }
        if (s[i] == 'y' || s[i] == 'Y') {
            count2++;
        }
    }
    answer = count == count2;

    return answer;
}