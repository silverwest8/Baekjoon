#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b) {
    return a.second > b.second;
}

bool compare2(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays) {
    std::vector<int> answer;
    std::vector<std::pair<std::string, int>> v;
    
    for (int i = 0; i < genres.size(); i++) {
        int flag = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first == genres[i]) {
                v[j].second += plays[i];
                flag = 1;
                break;
            }
        }
        if (!flag) {
            v.emplace_back(std::make_pair(genres[i], plays[i]));
        }
    }
    
    std::sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); i++) {
        // std::cout << v[i].first << " " << v[i].second << "\n";
        std::vector<std::pair<int, int>> temp;
        for (int j = 0; j < genres.size(); j++) {
            // std::cout << plays[j] << " " << j << "\n";
            if (v[i].first == genres[j]) {
                temp.emplace_back(std::make_pair(plays[j], j));
            }
        }
        std::sort(temp.begin(), temp.end(), compare2);
        for (int k = 0; k < temp.size(); k++) {
            // std::cout << temp[k].first << " " << temp[k].second << "!\n";
            if (k < 2) {
                answer.emplace_back(temp[k].second);
            }
        }
        
    }
    
    
    return answer;
}