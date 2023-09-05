#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int T = commands.size();
    for (int t = 0; t < T; t++) {
        int i = commands[t][0]-1;
        int j = commands[t][1]-1;
        int k = commands[t][2]-1;
        std::vector<int> temp;
        for (int l = i; l <= j; l++) {
            temp.push_back(array[l]);
        }
        // for (int q = 0; q < temp.size(); q++) {
        //     std::cout << temp[q] << " ";
        // }
        // std::cout << "\n";
        std::sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    return answer;
}