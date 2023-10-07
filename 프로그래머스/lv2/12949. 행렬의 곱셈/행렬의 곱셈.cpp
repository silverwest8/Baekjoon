#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), std::vector<int>(arr2[0].size(), 0));
    
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k]*arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}

/*
1 4    3 3    3 12  3 12
3 2    3 3    9 6   
4 1

15 15
15 15
15 15

2 3 2   5 4 3   22 22 11   10 6 6    8 12 2   6 3 2
4 2 4   2 4 1   36 28 18
3 1 4   3 1 1   29 20 14

*/
