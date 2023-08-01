#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int A, B;
    cin >> A >> B;

    cout << A * (B%10) << endl;
    cout << A * (int(B*0.1)%10) << endl;
    cout << A * (int(B*0.01)%10) << endl;
    cout << A * B << endl;

    return 0;
}