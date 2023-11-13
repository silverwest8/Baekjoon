#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string str = to_string(n);
    for(int i = 0; i < str.size(); i++) {
        answer += stoi(to_string(str[i]-'0'));
    }

    return answer;
}