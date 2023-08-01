#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int idx;
    string S;
    cin >> S;

    // 문자열 인덱스 index 찾기
    for (int i = 0; i < 26; i++) {
        idx = S.find('a'+i);
        cout << idx << " ";
    }
    return 0;
}