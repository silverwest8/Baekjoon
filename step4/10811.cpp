#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i;
    }
    for (int l = 0; l < M; l++) {
        int i, j;
        cin >> i >> j;
        // vector 순서 바꾸기
        reverse(v.begin()+(i-1), v.begin()+(j));
    }
    for (int i: v) {
        cout << i+1 << " ";
    }
    return 0;
}