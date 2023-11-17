#include <string>
#include <vector>
#include <set>
#include <iostream>

std::vector<int> number;
std::vector<bool> visited;
std::vector<int> v;
std::set<int> intSet;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int makeNum(std::vector<int> s) {
    std::string temp = "0";
    for (int i = 0; i < s.size(); i++) {
        temp += std::to_string(s[i]);
    }
    // std::cout << "test - " << temp << "\n";
    return std::stoi(temp);
}

void dfs(int n) {
    int tmp = makeNum(v);
    if (isPrime(tmp)) {
        intSet.insert(tmp);
        // std::cout << tmp << "\n";
    }
    for (int i = 0; i < number.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.emplace_back(number[i]);
            dfs(n+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(std::string numbers) {
    int answer = 0;
    
    for (int i = 0; i < numbers.size(); i++) {
        visited.emplace_back(false);
        number.emplace_back(numbers[i]-'0');
    }
    
    dfs(0);
    answer = intSet.size();
    
    return answer;
}