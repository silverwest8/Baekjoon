#include <string>
#include <vector>
#include <iostream>

std::string b, t;
std::vector<std::string> word;
std::vector<std::string> v;
std::vector<bool> visited;
int min = 51;

bool compare(std::string a, std::string b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    if (count == 1) {
        return true;
    }
    return false;
}

bool test() {
    if (v.size() == 0 || t != v[v.size()-1] || v.size() > min) {
        return false;
    }
    std::string now = b;
    for (int i = 0; i < v.size(); i++) {
        if (compare(now, v[i]) != true) {
            return false;
        }
        now = v[i];
    }
    return true;
}

void DFS(int n) {
    if (test()) {
        min = std::min(min, n);
        return;
    }
    for (int i = 0; i < word.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (v.size() == 0 || compare(v[v.size()-1], word[i])) {
                v.emplace_back(word[i]);
                DFS(n+1);
                v.pop_back();
            }
            visited[i] = false;
        }
    }
}

int solution(std::string begin, std::string target, std::vector<std::string> words) {
    b = begin;
    t = target;
    for (int i = 0; i < words.size(); i++) {
        word.emplace_back(words[i]);
        visited.emplace_back(false);
    }

    int answer = 0;
    DFS(0);
    if (min != 51) answer = min;
    return answer;
}