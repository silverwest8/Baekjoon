#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int N = jobs.size();
    std::sort(jobs.begin(), jobs.end());
    
    struct cmp {
        bool operator()(vector<int> a, vector<int> b){
            return a[1]>b[1];
        }
    };
    priority_queue<vector<int>,vector<vector<int>>, cmp> pq;
    
    int now = 0;
    
    pq.push(jobs[0]);
    jobs.erase(jobs.begin());
    // while(!jobs.empty()) {
    //     if (jobs[0][0] == pq.top()[0]) {
    //         pq.push(jobs[0]);
    //         jobs.erase(jobs.begin());
    //     } else {
    //         break;
    //     }
    // }
    
    while(!pq.empty() || !jobs.empty()) {
        if (pq.empty()) {
            pq.push(jobs[0]);
            jobs.erase(jobs.begin());
        }
        std::vector<int> temp;
        temp = pq.top();
        pq.pop();
        
        int start, end;
        if (now < temp[0]) {
            now = temp[0];
        }
        start = now;
        end = start+temp[1];
        now = end;
        
        answer += (end-temp[0]);
        // std::cout << "## "<< end-temp[0] << " " << now << " " << answer << "\n";

        while(!jobs.empty()) {
            if (jobs[0][0] <= now) {
                pq.push(jobs[0]);
                // std::cout << "*" <<jobs[0][0] << " " << jobs[0][1] << "\n";
                jobs.erase(jobs.begin());
            } else {
                break;
            }
        }
        
    }
    answer /= N;
    return answer;
}