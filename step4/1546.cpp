#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    int N, max;
    cin >> N;
    vector<int> v(N);
    vector<double> v2(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    max = *max_element(v.begin(), v.end());
    for (int l = 0; l < N; l++) {
        v2[l] = v[l]/(double)max * 100;
    }
    cout << fixed;
    cout.precision(9);
    // vector 평균, 전체 더하기
    cout << accumulate(v2.begin(), v2.end(), 0.0) / (double)v2.size();
    return 0;
}