// https://www.acmicpc.net/problem/1748

// 주어진 숫자의 자리수-1까지 각 자리수 개수가 9, 90, 900... 으로 늘어나는 규칙 활용
// (주어진 숫자 - 해당 숫자 자리수의 가장 작은 수)를 더하면 됨

#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    unsigned long long N, result = 0;
    std::string N_string;
    std::cin >> N_string;
    N = std::stoull(N_string);
    // 1-9 9
    // 10-99 90
    // 100-999 900
    // 1000-9999 9000
    // ...
    // 10000000-99999999
    // 100000000
    for (int i = 1; i < N_string.size(); i++) {
        std::string nine = "9";
        for (int j = 1; j < i; j++) {
            nine += "0";
        }
        result += (std::stoull(nine))*i;
    }
    std::string one = "1";
    for (int j = 1; j < N_string.size(); j++) {
        one += "0";
    }
    result += (N-std::stoull(one)+1)*N_string.size();
    std::cout << result;
    return 0;
}
