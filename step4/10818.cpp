#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (int argc, char* argv[]) {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cout << vec.front() << " " << vec.back();
    return 0;
}