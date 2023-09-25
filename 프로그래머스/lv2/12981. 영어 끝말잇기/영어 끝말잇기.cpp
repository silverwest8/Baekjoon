#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char before;
    int turn = 0;
    int find = 0;
    
    for(int i = 0; i < words.size(); i++) {
        if (i%n == 0) turn++;
        if (i == 0) {
            before = words[i][words[i].size()-1];
            continue;
        } else {
            std::sort(words.begin(), words.begin()+i);
            if (words[i][0] != before || std::binary_search(words.begin(), words.begin()+i, words[i])) {
                answer.emplace_back(i%n+1);
                answer.emplace_back(turn);
                find = 1;
                break;
            }
            before = words[i][words[i].size()-1];
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    // cout << "Hello Cpp" << endl;
    if (!find) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }

    return answer;
}