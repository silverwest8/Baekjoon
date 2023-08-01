#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int A, B;
    cin >> A >> B;
    cout << fixed;
    cout.precision(9);
    cout << A/(double)B;
    return 0;
}