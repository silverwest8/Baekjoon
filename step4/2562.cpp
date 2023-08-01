#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 벡터 복사, 정렬, 인덱스

int main (int argc, char* argv[]) {
    int N=9;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    vector<int> vec2;
    vec2.resize(vec.size());
    copy(vec.begin(), vec.end(), vec2.begin());
    sort(vec.begin(), vec.end());
    cout << vec.back() << endl;
    cout << find(vec2.begin(), vec2.end(), vec.back())-vec2.begin()+1 << endl;
    return 0;
}