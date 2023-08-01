#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[2] >= v[0]+v[1]) {
        cout << (v[0]+v[1])*2-1;
    } else {
        cout << v[0]+v[1]+v[2];
    }

    return 0;
}

// int main(int argc, char* argv[]) {
//     int a, b, c;
//     cin >> a >> b >> c;
//     if (a >= b + c || b >= a + c || c >= a + b ) {
//         if (a >= b + c) {
//             cout << a+b+c - (a-(b + c)+1);
//         }
//         if (b >= a + c) {
//             cout << a+b+c - (b-(a + c)+1);
//         }
//         if (c >= a + b) {
//             cout << a+b+c - (c-(a + b)+1);
//         }
//     } else {
//         cout << a+b+c;
//     }

//     return 0;
// }