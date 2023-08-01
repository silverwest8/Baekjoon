#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(int n) {
    int num = n, result = 1;
    while (n/10) {
        n /= 10;
        result++;
    }
    return result;
}

int getSum(int n) {
    int result = n;
    string num = to_string(n);
    for (int i = count(n); i >= 1 ; i--) {
        result += (num[i-1]-48);
    }
    return result;
}

int main(int argc, char* argv[]) {
    int N, sum, gen;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        if(getSum(i) == N) {
            cout << i;
            break;
        }
        else if (i==N) {
            cout << 0;
        }
    }

    

    return 0;
}