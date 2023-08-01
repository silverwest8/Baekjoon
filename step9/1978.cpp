#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    int N, temp, count = 0;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int n: v) {
        for (int i = 2; i <= n; i++) {
            if (n%i == 0 && i != n) {
                break;
            }
            if (i == n) {
                count++;
            }
        }
    }

    cout << count;
    
    return 0;
}