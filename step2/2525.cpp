#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int A, B, C;
    cin >> A >> B >> C;
    int H = C / 60;
    int M = C % 60;
    if (B + M < 60){
        if (A+H < 24) {
            cout << A+H << " " << B+M ;
        } else {
            cout << A+H-24 << " " << B+M ;
        }
    } else {
        if (A+H+1 < 24) {
            cout << A+H+1 << " " << B+M-60 ;
        } else {
            cout << A+H-23 << " " << B+M-60 ;
        }
    }
    
    return 0;
}