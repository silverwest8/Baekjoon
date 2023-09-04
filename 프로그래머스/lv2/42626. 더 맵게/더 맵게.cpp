#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    bool success = false;
    int answer = 0;
    std::priority_queue<int, std::vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.size() >= 2 && pq.top() < K) {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        pq.push(temp1+2*temp2);
        answer++;
    }
    
    if (pq.top() >= K) return answer;
    else return -1;
    /*
    bool check(vector<int> &scoville, int K) {
        std::sort(scoville.begin(), scoville.end());
        if (scoville[0] >= K) return true;
        return false;
    }
    bool success = false;
    int N = scoville.size();
    std::sort(scoville.begin(), scoville.end());
    int answer = 0;
    for (int i = 0; i < N-1; i++) {
        // for (int j = 0; j < scoville.size(); j++) {
        //     std::cout << scoville[j] << " ";
        // }
        // std::cout << "\n";
        if (scoville[0] < K) {
            int temp1 = scoville[0];
            int temp2 = scoville[1];
            scoville.erase(scoville.begin());
            scoville.erase(scoville.begin());
            scoville.emplace_back(temp1+2*temp2);
            answer++;
        }
        if (check(scoville, K)) {
            success = true;
            break;
        }
    }
    if (success) return answer;
    else return -1;
    */
}