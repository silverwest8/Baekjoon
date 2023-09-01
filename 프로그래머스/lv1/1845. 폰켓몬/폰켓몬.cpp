#include <iostream>
#include <vector>
#include <algorithm>
// using namespace std;

int solution(std::vector<int> nums)
{
    int N = nums.size();
    std::vector<int> v;
    for (int i = 0; i < N; i++) {
        if (std::find(v.begin(), v.end(), nums[i]) == v.end()) {
            v.emplace_back(nums[i]);
            if (v.size() == N/2) break;
        }
    }
    return v.size();
}