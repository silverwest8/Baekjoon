#include <string>
#include <vector>
#include <unordered_set>
#define MAX 32000

using namespace std;

int getNumber(int what, int count) {
    int n = what;
    for (int i = 1; i < count; i++) {
        n *= 10;
        n += what;
    }
    return n;
}

int solution(int N, int number) {
    int answer = -1;
    std::unordered_set<int> arr[9];
    
    
    for (int k = 1; k <= 8; k++) {
        arr[k].insert(getNumber(N, k));
        
        
        for (int i = 1; i < k; i++) {
            
            
            for (unordered_set<int>::iterator iter = arr[i].begin(); iter != arr[i].end(); iter++) {
                for (unordered_set<int>::iterator iter2 = arr[k-i].begin(); iter2 != arr[k-i].end(); iter2++) {
                    arr[k].insert((*iter)+(*iter2));
                    arr[k].insert((*iter)-(*iter2));
                    arr[k].insert((*iter2)-(*iter));
                    arr[k].insert((*iter)*(*iter2));
                    if (*iter2 != 0) {
                        arr[k].insert((*iter)/(*iter2));
                    }
                    if (*iter != 0) {
                        arr[k].insert((*iter2)/(*iter));
                    }
                }
            }
                
            
        }
        
        if (arr[k].find(number) != arr[k].end()) {
            answer = k;
            break;
        }
        
    }
    
    
    return answer;
}