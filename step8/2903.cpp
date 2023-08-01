#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int N, result;
    cin >> N;
    result = pow(pow(2, N)+1, 2);
    cout << result;

    return 0;
}