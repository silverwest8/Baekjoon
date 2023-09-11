#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    std::vector<int> v;
    
    for (int i = 0; i < progresses.size(); i++) {
        int temp = std::ceil( (float)(100-progresses[i])/speeds[i] );
        v.emplace_back(temp);
    }
    
    // for (int i = 0; i < v.size(); i++) {
    //     std::cout << v[i] << " ";
    // }
    
    int save;
    for (int i = 0; i < v.size(); i++) {
        if (answer.size() == 0) {
            answer.emplace_back(1);
            save = v[i];
        }
        else {
            if (save < v[i]) {
                answer.emplace_back(1);
                save = v[i];
            } else {
                answer[answer.size()-1]++;
            }
        }
    }
    
    std::cout << "\n";
    return answer;
}