#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
    int N, v, cnt=0;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> v;
    for (int i = 0; i < N; i++) {
        if (arr[i] == v) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}