#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    int N;
    cin >> N;
    for (int i = 1; i < 2*N; i++) {
        if (i <= N) {
            for (int j = 0; j < ((2*N-1) - (2*i-1)) / 2; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2*i-1); j++) {
                cout << "*";
            }
        } else {
            for (int j = 0; j < ((2*N-1) - (2*(2*N-i)-1)) / 2; j++) {
                cout << " ";
            }
            for (int j = 0; j < (2*(2*N-i)-1); j++) {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}