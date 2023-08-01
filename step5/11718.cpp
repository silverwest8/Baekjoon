#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string S;

    while (true) {
        getline(cin, S);
        if(S == "") break;
        cout << S << "\n";
    }
    return 0;
}