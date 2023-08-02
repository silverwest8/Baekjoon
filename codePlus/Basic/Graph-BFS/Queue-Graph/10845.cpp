#include <iostream>
#include <sstream>
#include <queue>
#include <string>

int main(int argc, char* argv[]) {
    int N, n;
    std::string s, s1;
    std::queue<int> q;

    std::cin >> N;
    std::getline(std::cin, s);
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, s);
        if (s.find(" ") != std::string::npos) {
            std::stringstream ss(s);
            std::string buffer;
            std::getline(ss, buffer, ' ');
            s1 = buffer;
            std::getline(ss, buffer, ' ');
            n = stoi(buffer);
        }

        if (s1 == "push") {
            q.push(n);
            s1 = "";
        } else if (s == "pop") {
            if (q.empty()) std::cout << -1 << "\n";
            else {
                std::cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "size") {
            std::cout << q.size() << "\n";
        } else if (s == "empty") {
            if (q.empty()) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        } else if (s == "front") {
            if (q.empty()) std::cout << -1 << "\n";
            else std::cout << q.front() << "\n";
        } else if (s == "back") {
            if (q.empty()) std::cout << -1 << "\n";
            else std::cout << q.back() << "\n";
        }
    }

    return 0;
}