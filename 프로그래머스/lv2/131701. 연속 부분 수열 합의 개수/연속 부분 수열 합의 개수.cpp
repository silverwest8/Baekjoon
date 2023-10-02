#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    std::set<int> s;
    for (int i = 0; i < elements.size(); i++) {
        int sum = 0;
        for (int j = 0; j < elements.size(); j++) {
            if (i+j < elements.size()) {
                sum += elements[i+j];
            } else {
                sum += elements[i+j-elements.size()];
            }
            s.insert(sum);
        }
    }
    
    answer = s.size();
//     int size = elements.size();
//     std::set<int> s;
    
//     std::list<int> l(elements.begin(), elements.end());
    
//     for (auto &i : l) {
//         std::cout << i << " ";
//     }
//     std::cout << "\n";
    
//     for (int i = 0; i < elements.size(); i++) {
//         int sum = 0;
//         auto it = v.begin()+i;
//         while(it) {
//             sum += &it;
//             set.push(sum);
//             auto it = std::next(it, 2);
//         }
//     }
    return answer;
}