#include <string>
#include <vector>

std::string solution(std::string number, int k) {
    std::string answer = "";
    int n = number.size() - k;
    int start = 0;
    for(int i = 0; i < n; i++) {
        char max = number[start];
        int maxIdx = start;
        for(int j = start; j < i+k+1; j++) {
            if(max < number[j]) {
                max = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += max;
    }
    
    
    return answer;
}