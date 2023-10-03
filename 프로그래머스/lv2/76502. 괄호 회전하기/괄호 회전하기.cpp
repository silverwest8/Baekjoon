#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i = 0;
    while (i < s.size()) {
        // std::cout << i << " " << s << "\n";
        std::stack<int> st;
        for(int j = 0; j < s.size(); j++) {
            if (!st.empty()) {
                char top = st.top();
                if (top == '[' && s[j] == ']') {
                    st.pop();
                    continue;
                } else if (top == '(' && s[j] == ')') {
                    st.pop();
                    continue;
                } else if (top == '{' && s[j] == '}') {
                    st.pop();
                    continue;
                }
            }

            st.push(s[j]);
        }
        if (st.empty()) answer++;
        

        s = s.substr(1, s.size())+s[0];
        i++;
    }
    return answer;
}