#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // std::vector<std::string> wants;
    // for (int i = 0; i < want.size(); i++) {
    //     for (int j = 0; j < number[i]; j++) {   
    //         wants.emplace_back(wants[i]);
    //     }
    // }
    // std::vector<int> number2(want.size(), 0);
    // std::vector<std::vector<int>> v(want.size(), std::vector<int>());
    // for (int i = 0; i < want.size(); i++) {
    //     for (int j = 0; j < discount.size(); j++) {
    //         if (discount[j] == want[i]) {
    //             number2[i]++;
    //             v[i].emplace_back(j+1);
    //         }
    //     }
    // }
    
    // discount 14개
    for (int i = 0; i <= discount.size()-10; i++) {
        for (int j = 0; j < want.size(); j++) {
            if (std::count(discount.begin()+i, discount.begin()+i+10, want[j]) < number[j]) {
                break;
            }
            if (j == want.size()-1) {
                answer++;
            }
        }
    }
    
    // for (int i = 0; i < want.size(); i++) {
    //     for (int j = 0; j < v[i].size(); j++) {
    //         std::cout << v[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    // for (int i = 0; i < number.size(); i++) {
    //     std::cout << number[i] << "\n";
    // }
    // for (int i = 0; i < number2.size(); i++) {
    //     std::cout << number2[i] << "\n";
    // }
    
    return answer;
}