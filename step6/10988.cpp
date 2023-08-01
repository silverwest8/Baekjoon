#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string S, R;
    cin >> S;
    R = S;
    reverse(R.begin(), R.end());
    cout << [](string S, string R) {
        return S.compare(R) == 0;
    }(S, R);
    return 0;
}