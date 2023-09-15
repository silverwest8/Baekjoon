#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split(string input, char del) {
    stringstream ss(input);
    string buffer;
    vector<int> result;
    while(getline(ss, buffer, del)) {
        result.push_back(std::stoi(buffer));
    }
    return result;
}

string solution(string s) {
    string answer = "";
    std::vector<int> temp = split(s, ' ');
    std::sort(temp.begin(), temp.end());
    answer += std::to_string(temp[0]);
    answer += " ";
    answer += std::to_string(temp[temp.size()-1]);
    return answer;
}