#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int X, i = 0;
    cin >> X;
    
    while (X > 0)
    {
        i++;
        X -= i;
    }
    if (i%2 == 0) {
        cout << i+X << "/" << 1-X;
    } else {
        cout << 1-X << "/" << i+X;
    }

    return 0;
}