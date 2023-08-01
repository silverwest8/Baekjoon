#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// pair second로 비교
bool compare(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

int main(int argc, char* argv[]) {
    string S;
    cin >> S;
    vector<pair<char, int>> v(26);
    for (char A = 'A'; A <= 'Z'; A++) {
        v[A-65].first = A;
    }
    for (char c: S) {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (c == i || c == i + 32) {
                v[i-'A'].second++;
            }
        }
    }

    sort(v.begin(), v.end(), compare);
    if (v[0].second == v[1].second) {
        cout << '?';
    } else {
        cout << v[0].first;
    }
    return 0;
}