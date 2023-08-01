#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int N, x_min , y_min , x_max , y_max , x, y;
    cin >> N;

    cin >> x >> y;
    x_max = x;
    x_min = x;
    y_max = y;
    y_min = y;

    for (int i = 1; i < N; i++) {
        cin >> x >> y;
        if (x > x_max) x_max = x;
        if (x < x_min) x_min = x;
        if (y > y_max) y_max = y;
        if (y < y_min) y_min = y;
    }
    
    cout << (x_max-x_min)*(y_max-y_min);
    return 0;
}