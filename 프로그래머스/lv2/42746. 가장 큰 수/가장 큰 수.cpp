#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) { //string으로 비교 수행
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;
    
	for (int i = 0; i < numbers.size(); i++){
        tmp.push_back(to_string(numbers[i]));
    }
    
	sort(tmp.begin(), tmp.end(), cmp);
    
	for (int i = 0; i < tmp.size(); i++) {
        answer += tmp[i]; 
    }
    
	if (answer[0] == '0') {
        answer = "0";
	}
    
	return answer;
}

/*
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

string solution(vector<int> numbers) {    

    string answer = "";
    std::vector<std::string> number;
    for (int i = 0; i < numbers.size(); i++) {
        number.emplace_back(std::to_string(numbers[i]));
    }
    while(!number.empty()) {
        int max = -1;
        std::vector<pair<int, int>> temp;
        for (int i = 0; i < number.size(); i++) {
            if (max < number[i][0] - '0') {
                max = number[i][0] - '0';
            }
        }
        for (int i = 0; i < number.size(); i++) {
            if (number[i][0] - '0' == max) {
                std::string cut = "";
                cut = number[i].substr(1, number[i].size());
                if (cut == "") cut = std::to_string(max);
                // std::cout << "cut == " << cut << "\n";
                temp.emplace_back(std::make_pair(std::stoi(cut), i));
            }
        }
        
        
        std::sort(temp.begin(), temp.end(), std::greater<>());
        
        // for (int i = 0; i < temp.size(); i++) {
        //     std::cout << temp[i].first << " "<< temp[i].second << "\n";
        // }
        // std::cout << "\n";
        
        
        for (int i = 0; i < temp.size(); i++) {
            int idx = temp[i].second;
            // std::cout << "+= " << number[idx] << "\n";
            answer += number[idx];
            // number.erase(std::remove(number.begin(), number.end(), number[idx]));
            // number.erase(number.begin()+idx);
        }
        
        std::sort(temp.begin(), temp.end(), cmp);
        // for (int i = 0; i < temp.size(); i++) {
        //     std::cout << temp[i].first << " "<< temp[i].second << "\n";
        // }
        // std::cout << "\n";
        
        for (int i = 0; i < temp.size(); i++) {
            int idx = temp[i].second;
            number.erase(number.begin()+idx);
        }
        // std::cout << "answer == " << answer << "\n\n";
        
        // for (int i = 0; i < number.size(); i++) {
        //     std::cout << number[i] << " ";
        // }
        // std::cout << "\n";
        
    }
    return answer;
}
*/