#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    std::vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            v.emplace_back(1);
        } else {
            if (v.size() == 0) return false;
            else v.pop_back();
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;
    // std::cout << v.size() << "\n";
    if (v.size() != 0) return false;
    else return true;
}