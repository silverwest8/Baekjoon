#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string A, B;
    int a, b;
    cin >> A >> B;

    // 문자열 뒤집기
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    a = stoi(A);
    b = stoi(B);
    auto result = [](int a, int b) {
        if (a > b) return a;
        else return b;
    }(a, b);
    cout << result;
    
    return 0;
}