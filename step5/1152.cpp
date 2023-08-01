#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// trim()

// trim from start (in place)
static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string &s) {
    rtrim(s);
    ltrim(s);
}

// split
vector<string> split(string input, char del) {
    stringstream ss(input);
    string buffer;
    vector<string> result;
    while(getline(ss, buffer, del)) {
        result.push_back(buffer);
    }
    return result;
}

int main(int argc, char* argv[]) {
    int N;
    string S;
    getline(cin, S);
    trim(S);
    cout << split(S, ' ').size();
    
    return 0;
}