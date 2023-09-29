#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcf(int n, int m) { // greatest common factor
    int result, a;
    if (n>m) {
        a = n % m;
        while(a) {
            n = m;
            m = a;
            a = n % m;
        }
        return m;
    } else {
        a = m % n;
        while(a) {
            m = n;
            n = a;
            a = m % n;
        }
        return n;
    }
    return result;
}

int lcm (int a, int b) {
    int result, gcn;
    gcn = gcf(a, b);
    result =  a * b / gcn;
    return result;
}

int solution(vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    int answer = 0;
    int temp = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        temp = lcm(temp, arr[i]);
    }
    answer = temp;
    return answer;
}