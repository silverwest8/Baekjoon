#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N = 10;
    vector<int> v(N);
    vector<int> v2(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        v2[i] = v[i]%42;
    }
    // 벡터 중복 제거
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    
    cout << v2.size();
    return 0;
}