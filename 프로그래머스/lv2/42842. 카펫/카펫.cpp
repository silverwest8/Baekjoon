#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    std::vector<std::vector<int>> v;
    
    for (int i = 1; i <= yellow; i++) {
        if (yellow%i == 0) {
            std::vector<int> temp;
            temp.emplace_back(i);
            temp.emplace_back(yellow/i);
            v.emplace_back(temp);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i][0]*2 + v[i][1]*2 + 4 == brown) {
            answer.emplace_back(v[i][1]+2);
            answer.emplace_back(v[i][0]+2);
            break;
        }
    }
    return answer;
}

/*
24 =    1*24 -> 1*2 + 24*2 + 4
        2*12 -> 2*2 + 12*2 + 4
        3*8  -> 3*2 + 8*2 + 4
        4*6  -> 4*2 + 6*2 + 4
*/