#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int T;
    string S;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> S;
        cout << S[0] << S[S.size()-1] << endl;
    }
    return 0;
}