#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.emplace_back(0);
    answer.emplace_back(0);
    
    while(true) {
        int count = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '0') count++;
        }
        int len = size - count;
        // len을 2진수로 바꿔야 함
        s = "";
        while(len) {
            s += std::to_string(len % 2);
            len /= 2;
        }
        
        answer[0]++;
        answer[1]+=count;
        // std::cout << answer[0] << "\n";
        // std::cout << answer[1] << "\n";
        
        if (s.size() == 1) break;
    }
    // 111111 -> 10000 -> 1
    return answer;
}