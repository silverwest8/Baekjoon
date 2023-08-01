#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int N, cnt = 0, find = 0;
    cin >> N;

    for (int a = 1000; a >= 0 ; a--) {
        int b = 0;
        while (5*a+3*b <= N)
        {
            if (5*a+3*b == N) {
                cout << a+b << endl;
                find = 1;
                break;
            }
            b++;
        }
        if (find) break;
    }
    if (!find) cout << -1;
    
    return 0;
}
