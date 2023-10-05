#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);
    vector<int> answer(right-left+1);
    // std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
    
    long long start_x = left/n, start_y = left%n;
    long long end_x = right/n, end_y = right%n;
    
    // for (int k = 0; k < n; k++) {
    //     for (int i = 0; i <= k; i++) {
    //         for (int j = 0; j <= k; j++) {
    //             if (v[i][j] == 0) {
    //                 v[i][j] = k+1;
    //                 if (i > start_x && i < end_x || (i == start_x && j >= start_y) || (i == end_x && j <= end_y) ) {
    //                     answer.emplace_back(v[i][j]);
    //                 }
    //                 // if (i > end_x || (i == end_x && j > end_y )) {
    //                 //     continue;
    //                 // }
    //                 // answer.emplace_back(v[i][j]);
    //             }
    //         }
    //     }
    // }
    
    // for (int i = 0; i < right-left+1; i++) {
    //     answer[i] = 
    // }
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i < start_x) {
            continue;
        }
        if (i > end_x) {
            break;
        }
        for (int j = 0; j < n; j++) {
            // if (i >= j) {
            //     v[i][j] = i+1;
            // } else {
            //     v[i][j] = j+1;
            // }
            // if (i < start_x || (i == start_x && j < start_y )) {
            //     continue;
            // }
            // if (i > end_x || (i == end_x && j > end_y )) {
            //     continue;
            // }
            
            if (i == start_x && j < start_y ) {
                continue;
            }
            if (i == end_x && j > end_y ) {
                break;
            }
            if (i >= j) {
                // answer.emplace_back(i+1);
                answer[k] = i+1;
                k++;
            } else {
                // answer.emplace_back(j+1);
                answer[k] = j+1;
                k++;
            }
            // answer.emplace_back(v[i][j]);
        }
    }
    
//     for (int i = 0; i < v.size(); i++) {
//         for (int j = 0; j < v[i].size(); j++) {
//             std::cout << v[i][j] << " ";
//         }
//         std::cout << "\n";
//     }
    
    
    
    // for (int i = 0; i < v.size(); i++) {
    //     for (int j = 0; j < v[i].size(); j++) {
    //         if (i < start_x || (i == start_x && j < start_y )) {
    //             continue;
    //         }
    //         if (i > end_x || (i == end_x && j > end_y )) {
    //             continue;
    //         }
    //         answer.emplace_back(v[i][j]);
    //     }
    // }
    
    
    return answer;
}