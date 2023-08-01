#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int x, y, z;

    while (true)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) {
            break;
        }
        if (x >= y + z || y >= x + z || z >= x + y ) {
            cout << "Invalid" << endl;
        } else if (x == y && y == z) {
            cout << "Equilateral" << endl;
        } else if (x == y || y == z || x == z) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Scalene" << endl;
        }
    }

    return 0;
}