#include <string>
#include <vector>
#include <map>
// #include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    std::map<std::string, std::vector<std::string>> m;
    for (int i = 0; i < clothes.size(); i++) {
        if (m.find(clothes[i][1]) != m.end()) {
            m.insert(std::make_pair(clothes[i][1], std::vector<std::string>()));
        }
        m[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for (auto item: m) {
        // std::cout << item.second.size() << " ";
        answer *= (item.second.size()+1);
    }
    answer--;
    
    return answer;
}