#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    // 논문 n편
    // h번 이상 인용된 논문이 h편 이상이고
    // h번 이하 인용된 논문이 나머지
    // h의 최대값
    int answer = 0;
    
    int n = citations.size();
    std::sort(citations.begin(), citations.end(), std::greater<>());
    // 0 1 3 5 6
    // 6 5 3 1 0
    // 0 0 0
    
    // 6 6 6 6 6
    for (int h = citations[0]; h >= 0; h--) {
        // std::cout<< h << "\n";
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                count++;
            } else {
                count2++;
            }
            if (count >= h) {
                answer = h;
                return answer;
            }
        }
    }
    return answer;
    
}