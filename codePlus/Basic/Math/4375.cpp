#include <iostream>

// 다시보기

/*
int 범위를 넘는 stoi -> stoll but 여기선 안쓰임(범위가 long long 넘어감)
std::string make_one(int n) {
    std::string result = "", one = "1";
    for (int i = 0; i < n; i++) {
        // 문자열 string 붙이기
        result.append(one);
    }
    return result;
}
*/


// 참고할 모듈러 연산 공식(나머지 연산)
// x mod n = (x mod n) mod n
// (a + b) mod n = (a mod n + b mod n) mod n
// (a * b) mod n = (a mod n * b mod n) mod n
int main(int argc, char* argv[]) {
    int base, i, ans;
    std::string s, one;

    while (std::cin >> base) {
        i = 1;
        ans = 1;
        while(true) {
            if (i%base == 0) {
                std::cout << ans << "\n";
                break;
            }
            ans++; //자릿수
            i = i*10+1;
            i %= base;
        }
    }

    return 0;
}