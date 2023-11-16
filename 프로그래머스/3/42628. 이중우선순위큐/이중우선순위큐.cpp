#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

std::vector<int> solution(std::vector<std::string> operations) {
    std::vector<int> answer;
    
    std::deque<int> d;
    
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            int temp = std::stoi(operations[i].substr(2));
            d.push_back(temp);
            std::sort(d.begin(), d.end(), std::greater<>());
            continue;
        }
        if (operations[i][0] == 'D') {
            int temp = std::stoi(operations[i].substr(2));
            if (!d.empty() && temp == -1) {
                d.pop_back();
                continue;;
            }
            if (!d.empty() && temp == 1) {
                d.pop_front();
                continue;;
            }
        }
    }
    
    if (d.size() == 0) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    } else {
        answer.emplace_back(d.front());
        answer.emplace_back(d.back());
    }
    
    return answer;
}