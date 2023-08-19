// 2023.8.10. 13:10 - 
#include <iostream>
#include <sstream>
// #include <set>

int N;
unsigned result = 0, one = 1;

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n;
    std::string temp, buffer;
    std::string command;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> n;
            result |= one << n;
        } else if (command == "remove") {
            std::cin >> n;
            result &= ~(one << n);
        } else if (command == "check") {
            std::cin >> n;
            if (result & (one << n)) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        } else if (command == "toggle") {
            std::cin >> n;
            result ^= one << n;
        } else if (command == "all") {
            result = (1 << 21) -1;
        } else if (command == "empty") {
            result = 0;
        }
    }
    return 0;
}

/*
int main(int argc, char* argv[]) {
    int n;
    std::set<int> s;
    std::string temp, buffer;
    std::string command;
    std::cin >> N;
    std::getline(std::cin, temp);
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, temp);
        std::stringstream ss(temp);
        command = temp;
        if (temp.find(' ') != std::string::npos) {
            std::getline(ss, buffer, ' ');
            command = buffer;
            std::getline(ss, buffer, ' ');
            n = std::stoi(buffer);
        }
        if (command == "add") {
            s.insert(n);
        } else if (command == "remove") {
            s.erase(s.find(n));
        } else if (command == "check") {
            if (s.find(n) != s.end()) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        } else if (command == "toggle") {
            if (s.find(n) != s.end()) { // 있으면
                s.erase(s.find(n));
            } else { // 없으면
                s.insert(n);
            }
        } else if (command == "all") {
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        } else if (command == "empty") {
            s.clear();
        }
    }
    return 0;
}
*/