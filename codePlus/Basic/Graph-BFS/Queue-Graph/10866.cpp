#include <iostream>
#include <string>
#include <deque>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, n;
    std::deque<int> d;
    std::string s, s1, buffer;
    std::cin >> N;
    std::getline(std::cin, s);
    for (int i = 0; i < N; i++) {
        s = "";
        s1 = "";
        std::getline(std::cin, s);
        if (s.find(" ") != std::string::npos) {
            std::stringstream ss(s);
            std::getline(ss, buffer, ' ');
            s1 = buffer;
            std::getline(ss, buffer, ' ');
            n = std::stoi(buffer);
        }
        if (s1 == "push_front") {
            d.push_front(n);
        } else if (s1 == "push_back") {
            d.push_back(n);
        } else if (s == "pop_front") {
            if (d.empty()) std::cout << -1 << "\n";
            else  {
                std::cout << d.front() << "\n";
                d.pop_front();
            }
        } else if (s == "pop_back") {
            if (d.empty()) std::cout << -1 << "\n";
            else  {
                std::cout << d.back() << "\n";
                d.pop_back();
            }
        } else if (s == "size") {
            std::cout << d.size() << "\n";
        } else if (s == "empty") {
            if (d.empty()) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        } else if (s == "front") {
            if (d.empty()) std::cout << -1 << "\n";
            else std::cout << d.front() << "\n";
        } else if (s == "back") {
            if (d.empty()) std::cout << -1 << "\n";
            else std::cout << d.back() << "\n";
        }
    }

    return 0;
}

/*
// split 구현 외우기
std::vector<std::string> split(std::string input, std::string delimiter) {
    std::vector<std::string> ret;
    long long pos = 0;
    std::string token = "";
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length()) ;
    }
    ret.push_back(input);
    return ret;
}
*/