#include <string>
#include <vector>

// 78(1001110) 83(1010011)
// 1(1) 2(10)
// (1100) (11000)
// (10100)

// (00)
// (01)
// (10)
// (11)
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int nn = n;
    int count1_save = 0;
    std::string nn2 = "";

    while(nn) {
        std::string temp = std::to_string(nn % 2);
        if (temp == "1") count1_save++;
        nn2 += temp;
        nn /= 2;
    }
    
    
    while(true) {
        n++;
        int nnn = n;
        std::string nnn2 = "";
        int count1 = 0;
        while(nnn) {
            string temp = std::to_string(nnn % 2);
            if (temp == "1") count1++;
            nnn2 += temp;
            nnn /= 2;
        }
        if (count1 == count1_save) {
            answer = n;
            break;
        }
    }
    // dfs(N);
    
    
    
    return answer;
}