#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int N, i = 1;
    cin >> N;
    
    N--;
    while (N > 0)
    {
        N -= 6*i;
        i++;
    }

    cout << i;

    return 0;
}