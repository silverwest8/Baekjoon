#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string S;
    char temp;
    vector<vector<char>> words(15, vector<char> (15, 0));
    for (int i = 0; i < 5; i++) {
        cin >> S;
        for (int j = 0; j < S.size(); j++) {
            words[i][j] = S[j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < words.size(); j++) {
            temp = words[i][j];
            words[i][j] = words[j][i];
            words[j][i] = temp;
        }
    }

    // for (int j = 0; j < words.size(); j++) {
    //     for (int i = 0; i < 5; i++) {
    //         if (words[j][i] == 0) {
    //             cout << ' ' << ' ';
    //         } else {
    //             cout << words[j][i] << ' ';
    //         }
    //     }
    //     cout << "\n";
    // }

    for (int j = 0; j < words.size(); j++) {
        for (int i = 0; i < 5; i++) {
            if (words[j][i] != 0) {
                cout << words[j][i];
            }
        }
    }

    return 0;
}