#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int N, count;
    cin >> N;
    count = N / 4;
    if (N%4) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        cout << "long ";
    }
    cout << "int";
    return 0;
}