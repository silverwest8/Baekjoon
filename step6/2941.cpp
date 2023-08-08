#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {
    vector<string> list = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string S;
    int cnt = 0;
    cin >> S;

    while (S.size())
    {
        if (S.size() >= 3) {
            string s3 = S.substr(0, 3);
            string s2 = S.substr(0, 2);
            // 앞에 2글자가 list 안에 포함되어 있으면
            // vector find
            if (find(list.begin(), list.end(), s3) != list.end()) {
                S = S.substr(3);
            } else if (find(list.begin(), list.end(), s2) != list.end()) {
                S = S.substr(2);
            } else {
                S = S.substr(1);
            }
        } else if (S.size() >= 2) {
            string s2 = S.substr(0, 2);
            if (find(list.begin(), list.end(), s2) != list.end()) {
                S = S.substr(2);
            } else {
                S = S.substr(1);
            }
        } else {
            S = S.substr(1);
        }
        cnt++;
    }

    cout << cnt;
    
    return 0;
}