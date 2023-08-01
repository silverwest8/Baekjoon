#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int A, B, C;
    cin >> A >> B >> C;

    if (A==B && B==C) {
        cout << 10000+A*1000;
    } else if (A==B || B==C || A==C) {
        if (A==B || B==C) {
            cout << 1000+B*100;
        } else {
            cout << 1000+A*100;
        }
    } else {
        if (A > B) {
            if (A > C) {
                cout << A*100;
            } else {
                cout << C*100;
            }
        } else {
            if (B > C) {
                cout << B*100;
            } else {
                cout << C*100;
            }
        }
    }
    return 0;
}