#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int T, C, Q = 25, D = 10, N = 5, P = 1, Q_num = 0, D_num = 0, N_num = 0, P_num = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> C;

        Q_num = C/Q;
        C -= Q*Q_num;

        D_num = C/D;
        C -= D*D_num;

        N_num = C/N;
        C -= N*N_num;

        P_num = C;

        cout << Q_num << " " << D_num << " " << N_num << " " << P_num << endl;
    }

    return 0;
}