#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    std::vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        if (answer.size() == 0 || answer[answer.size()-1] != arr[i]) {
            answer.emplace_back(arr[i]);
        }
    }

    return answer;
}