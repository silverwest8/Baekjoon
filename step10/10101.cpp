#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int x, y, z;
    cin >> x >> y >> z;

    if (x + y + z != 180) {
        cout << "Error";
    } else if (x == y && y == z) {
        cout << "Equilateral";
    } else if (x == y || y == z || x == z) {
        cout << "Isosceles";
    } else {
        cout << "Scalene";
    }

    return 0;
}