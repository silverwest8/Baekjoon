#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int N, temp = 666, cnt = 0;
    cin >> N;

    while (true)
    {
        string s = to_string(temp);
        if (s.find("666") != string::npos) {
            cnt++;
            if (cnt == N) {
                cout << temp;
                break;
            }
        }
        temp++;
    }
    
    return 0;
}
