#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    string N;
    int B, n, result = 0, x;
    cin >> N >> B;

    for (int i = 0; i < N.size(); i++) {
        n = N.size()-i-1;
        if (N[i] >= 'A' && N[i] <= 'Z') {
            x = N[i]-55;
            result += (x * pow(B, n));
        } else {
            x = N[i]-48;
            result += (x * pow(B, n));
        }
    }

    cout << result;

    return 0;
}