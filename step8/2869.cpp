#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int A, B, V;
    cin >> A >> B >> V;
    
    double x = (V-B) / double(A-B);
    int int_x = (int)x;
    if (x > int_x) int_x++;

    cout << int_x;

    return 0;
}