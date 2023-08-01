#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int x, y, w, h, min;
    cin >> x >> y >> w >> h;
    min = w >= h ? w : h;
    
    if (x < min) min = x;
    if (w-x < min) min = w-x;
    if (y < min) min = y;
    if (h-y < min) min = h-y;

    cout << min;
    return 0;
}