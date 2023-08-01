#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 벡터 특정 값 삭제, 제거

int main(int argc, char* argv[]) {
    int N = 30;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i+1;
    }
    for (int l = 0; l < N-2; l++) {
        int temp;
        cin >> temp;
        v.erase(remove(v.begin(), v.end(), temp),v.end());
    }

    //벡터 출력
    for (int i: v) {
        cout << i << " ";
    }
    return 0;
}