#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int H, M;
    cin >> H >> M;
    if (H > 0){
        if (M >= 45) {
            cout << H << " " << M - 45;
        } else {
            cout << H-1 << " " << M + 15;
        }
    } else{
        if (M >= 45) {
            cout << H << " " << M - 45;
        } else {
            cout << H+23 << " " << M + 15;
        }
    }
    
    return 0;
}