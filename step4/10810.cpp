#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int l = 0; l < M; l++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (; i <= j; i++){
            v[i-1] = k;
        }
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}