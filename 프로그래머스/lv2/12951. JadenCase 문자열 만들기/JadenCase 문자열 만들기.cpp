#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
std::string removeDuplicateSpaces(std::string const &str) {
    std::string s;
    std::string word;
    std::istringstream ss(str);
 
    while (ss >> word) {
        if (!s.empty()) {
            s += ' ';
        }
        s += word;
    }
 
    return s;
}

std::vector<std::string> split(std::string s, char del) {
    stringstream ss(s);
    std::string buffer;
    std::vector<std::string> result;
    while(getline(ss, buffer, del)) {
        result.push_back(buffer);
    }
    return result;
}

string solution(string s) {
    string answer = "";
    string sss = s;
    std::cout << sss << "\n";
    std::vector<std::string> temp = split(sss, ' ');
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i][0] >= 'a' && temp[i][0] <= 'z') {
            temp[i][0] = temp[i][0] - ('a'-'A');
        }
        for (int j = 1; j < temp[i].size(); j++) {
            if (temp[i][j] >= 'A' && temp[i][j] <= 'Z') {
                temp[i][j] = temp[i][j] + ('a'-'A');
            }
        }
        if (i == 0) {
                answer += temp[i];
            } else {
                answer += " ";
                answer += temp[i];
            }
    }
    return answer;
}
*/

string solution(string s) {
    string answer = "";
    bool inside = false;// 단어 안에 있는지 여부
    for(auto c : s) {
        if (c == ' ') {
            answer += ' ';
            inside = false;
        } else if (!inside) {// 단어 첫번째이면
            answer += toupper(c);
            inside = true;
        } else {
            answer += tolower(c);
        }
    }
    return answer;
}