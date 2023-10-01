#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

std::vector<int> v(10000000+1, 0);

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for (int i = 0; i < tangerine.size(); i++) {
        v[tangerine[i]]++;
    }
    std::sort(v.begin(), v.end(), std::greater<>());
    
    // int j = 0;
    // while(true) {
    //     if (v[j]) {
    //         std::cout << v[j] << " ";
    //     } else {
    //         break;
    //     }
    //     j++;
    // }
    // std::cout << "\n";
    
    int i = 0;
    int sum = 0;
    while(true) {
        if (v[i] != 0) {
            sum+=v[i];
            if (sum >= k) {
                answer = i+1;
                break;
            }
        } else {
            break;
        }
        i++;
    }
    
    return answer;
}