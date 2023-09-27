#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    std::sort(people.begin(), people.end());
    int first = 0, last = people.size()-1;
    while(first <= last) {
        if (first == last) {
            answer++;
            break;
        }
        int min = people[first];
        int max = people[last];
        if (min+max <= limit) {
            first++;
            last--;
            answer++;
        } else {
            last--;
            answer++;
        }
    }
    
    return answer;
}