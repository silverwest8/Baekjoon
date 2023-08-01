#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int N, K;
    cin >> N >> K;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (!(N%i)) {
            v.push_back(i);
        }
    }
    cout << v[K-1];
    
    return 0;
}