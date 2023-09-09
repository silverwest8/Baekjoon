#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    std::unordered_map<std::string, int> um;
    for (int i = 0; i < participant.size(); i++) {
        if (um.find(participant[i]) == um.end()) {
            um.insert(std::make_pair(participant[i], 1));
        } else {
            um[participant[i]]++;
        }
    }
    for (int i = 0; i < completion.size(); i++) {
        if(um.find(completion[i]) != um.end()) {
            um[completion[i]]--;
        }
    }
    for (int i = 0; i < participant.size(); i++) {
        if (um[participant[i]] > 0) {
            answer = participant[i];
        }
    }
    // std::sort(participant.begin(), participant.end());
    // std::sort(completion.begin(), completion.end());
    
    // int i = 0;
    // for (; i < completion.size(); i++) {
    //     if (participant[i] != completion[i]) {
    //         break;
    //     }
    // }
    return answer;
}