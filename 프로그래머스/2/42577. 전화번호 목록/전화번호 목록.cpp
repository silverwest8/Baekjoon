#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    std::sort(phone_book.begin(), phone_book.end());
    // 접두어 있으면 false
    for (int i = 0; i < phone_book.size()-1; i++) {
        int len = std::min(phone_book[i].size(), phone_book[i+1].size());
        for (int j = 0; j < len; j++) {
            if (phone_book[i][j] != phone_book[i+1][j]) {
                break;
            }
            if (j == len-1){
                answer = false;
            }
        }
        if (!answer) {
            break;
        }
    }
    return answer;
}