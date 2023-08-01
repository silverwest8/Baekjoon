#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i+1;
    }
    for (int l = 0; l < M; l++) {
        int i, j, temp;
        cin >> i >> j;
        temp = v[i-1];
        v[i-1] = v[j-1];
        v[j-1] = temp;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}