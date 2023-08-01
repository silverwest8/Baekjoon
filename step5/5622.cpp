#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string S;
    int T = 0;
    cin >> S;

    for (char c: S) {
        if (c <= 'C') {
            T+=3;
        } else if (c <= 'F') {
            T+=4;
        } else if (c <= 'I') {
            T+=5;
        } else if (c <= 'L') {
            T+=6;
        } else if (c <= 'O') {
            T+=7;
        } else if (c <= 'S') {
            T+=8;
        } else if (c <= 'V') {
            T+=9;
        } else {
            T+=10;
        }
    }
    cout << T;
    
    return 0;
}