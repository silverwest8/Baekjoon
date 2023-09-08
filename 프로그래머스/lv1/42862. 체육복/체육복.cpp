#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(), reserve.end());
    
    for (int i = 1; i <= n; i++) {
        if (std::find(lost.begin(), lost.end(), i) != lost.end() && std::find(reserve.begin(), reserve.end(), i) != reserve.end()) {
            lost.erase(std::remove(lost.begin(), lost.end(), i), lost.end());
            reserve.erase(std::remove(reserve.begin(), reserve.end(), i), reserve.end());
        }
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i]-1 >= 1 && std::find(lost.begin(), lost.end(), reserve[i]-1) != lost.end()) {
            lost.erase(std::remove(lost.begin(), lost.end(), reserve[i]-1), lost.end());
            continue;
        }
        if (reserve[i]+1 <= n && std::find(lost.begin(), lost.end(), reserve[i]+1) != lost.end()) {
            lost.erase(std::remove(lost.begin(), lost.end(), reserve[i]+1), lost.end());
        }
        
    }
    return n-lost.size();
}