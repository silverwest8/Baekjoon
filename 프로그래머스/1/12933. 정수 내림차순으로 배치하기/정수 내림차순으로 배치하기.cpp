#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    std::vector<int> v;
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++) {
        v.emplace_back(str[i]-'0');
    }
    sort(v.begin(), v.end(), greater<>());
    string ans = "";
    for (int i = 0; i < v.size(); i++) {
        ans += to_string(v[i]);
    }
    answer = stoll(ans);
    return answer;
}