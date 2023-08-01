#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    for (x = -999; x <= 999; x++) {
        for (y = -999; y <= 999; y++) {
            if (a*x+b*y != c || d*x+e*y != f) continue;
                cout << x << " " << y;
        }
    }
    return 0;
}

// int main(int argc, char* argv[]) {
//     int a, b, c, d, e, f, x, y;
//     cin >> a >> b >> c >> d >> e >> f;

//     x = (c*e-b*f) / (a*e-b*d);
//     y = (c*d-a*f) / (b*d-a*e);
    
//     cout << x << " " << y;


//     return 0;
// }