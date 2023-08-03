#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int N, B, remain;
    string result = "";
    cin >> N >> B;

    while (N / B || N % B) {
        remain = N % B;
        if (remain >= 10 && remain <= 36) {
            // char to string
            result = string(1, (remain)+55) + result;
        } else {
            // int to string
            result = to_string(remain) + result;
        }
        
        N = N / B;
    }
    
    cout << result;

    return 0;
}