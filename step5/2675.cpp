#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int T, R;
    string S;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> R >> S;
        for (char c: S) {
            for (int j = 0; j < R; j++)
                cout << c;
        }
        cout << "\n";
    }
    
    return 0;
}