#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v(26);
    string S;
    char old, now;
    int N = 0, cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        old = S[0];
        v[old-'a'] = 1;
        S = S.substr(1);
        while(S.size()) {
            now = S[0];
            if (now == old) {
                S = S.substr(1);
                continue;
            } else {
                if (v[now-'a'] == 1) {
                    cnt++;
                    break;
                } else {
                    old = now;
                    v[old-'a'] = 1;
                    S = S.substr(1);
                }
            }
        }
        // vector 0으로 재초기화
        fill(v.begin(), v.end(), 0);
    }

    cout << (N-cnt);
    
    return 0;
}