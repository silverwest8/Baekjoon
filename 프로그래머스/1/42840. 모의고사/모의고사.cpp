#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> answers) {
    std::vector<int> answer;
    std::vector<std::pair<int, int>> v(3, std::make_pair(0, 0));
    v[0].second = 1;
    v[1].second = 2;
    v[2].second = 3;
    // int p1 = 0, p2 = 0, p3 = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (i % 5 == 0) {
            if (answers[i] == 1) v[0].first++;
        } else if (i % 5 == 1) {
            if (answers[i] == 2) v[0].first++;
        } else if (i % 5 == 2) {
            if (answers[i] == 3) v[0].first++;
        } else if (i % 5 == 3) {
            if (answers[i] == 4) v[0].first++;
        } else if (i % 5 == 4) {
            if (answers[i] == 5) v[0].first++;
        }
        
        // 2, 1, 2, 3, 2, 4, 2, 5
        if (i % 8 == 0 || i % 8 == 2 || i % 8 == 4 || i % 8 == 6) {
            if (answers[i] == 2) v[1].first++;
        } else if (i % 8 == 1) {
            if (answers[i] == 1) v[1].first++;
        } else if (i % 8 == 3) {
            if (answers[i] == 3) v[1].first++;
        } else if (i % 8 == 5) {
            if (answers[i] == 4) v[1].first++;
        } else if (i % 8 == 7) {
            if (answers[i] == 5) v[1].first++;
        }
        
        // 3, 3, 1, 1, 2, 2, 4, 4, 5, 5
        if (i % 10 == 0 || i % 10 == 1) {
            if (answers[i] == 3) v[2].first++;
        } else if (i % 10 == 2 || i % 10 == 3) {
            if (answers[i] == 1) v[2].first++;
        } else if (i % 10 == 4 || i % 10 == 5) {
            if (answers[i] == 2) v[2].first++;
        } else if (i % 10 == 6 || i % 10 == 7) {
            if (answers[i] == 4) v[2].first++;
        } else if (i % 10 == 8 || i % 10 == 9) {
            if (answers[i] == 5) v[2].first++;
        }
    }
    
    std::sort(v.begin(), v.end(), std::greater<>());
    
    std::cout << v[0].first << " " << v[1].first << " " << v[2].first << "\n";
    answer.emplace_back(v[0].second);
    if (v[1].first == v[0].first) answer.emplace_back(v[1].second);
    if (v[2].first == v[0].first) answer.emplace_back(v[2].second);
    std::sort(answer.begin(), answer.end());
    
    
    return answer;
}