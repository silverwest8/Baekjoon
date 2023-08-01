#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    int N, total;
    vector<int> v;

    while (true)
    {
        cin >> N;
        if (N < 0) {
            break;
        }
        for (int i = 1; i < N; i++) {
            if (N%i == 0) v.push_back(i);
        }
        total = accumulate(v.begin(), v.end(), 0);
        if (accumulate(v.begin(), v.end(), 0) == N) {
            cout << N << " = " << v[0];
            for (int i = 1; i < v.size(); i++) {
                cout << " + " << v[i];
            }
            cout << "\n";
        } else {
            cout << N << " is NOT perfect.\n";
        }
        v.clear();
    }
    
    return 0;
}