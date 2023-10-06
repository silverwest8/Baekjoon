#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    
    int answer = 0;
    
    std::sort(citations.begin(), citations.end(), std::greater<>());
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }
    
    return citations.size();
    /*
    
    std::sort(citations.begin(), citations.end(), std::greater<>());
    
    for (int h = citations[0]; h >= 0; h--) {
        int count = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                count++;
            }
            if (count >= h) {
                answer = h;
                return answer;
            }
        }
    }
    return answer;
    */
}