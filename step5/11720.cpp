#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int N, T = 0;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        T+=(int)S[i]-48;
    }
    cout << T;
    return 0;
}