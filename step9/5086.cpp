#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int A, B;
    while (true)
    {
        cin >> A >> B;
        if (A == B) {
            break;
        }
        if (!(B%A)) {
            cout << "factor" << endl;
        } else if (!(A%B)) {
            cout << "multiple" << endl;
        } else {
            cout << "neither" << endl;
        }
    }
    
    return 0;
}