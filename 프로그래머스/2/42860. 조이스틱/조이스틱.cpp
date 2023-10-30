#include <string>
#include <vector>
#include <iostream>

int N;
int Answer = 9999999;
std::string Copy = "";
std::string Name = "";

int findRight(std::string name, std::string copy, int cursor) {
    int count = 0;
    while (name[cursor] == copy[cursor]) {
        cursor++;
        cursor %= name.size();
        count++;
    }
    return count;
}

int findLeft(std::string name, std::string copy, int cursor) {
    int count = 0;
    while (name[cursor] == copy[cursor]) {
        cursor--;
        cursor += name.size();
        cursor %= name.size();
        count++;
    }
    return count;
}

void DFS(int n, int sum, std::string copy, int cursor) {
    
    int next1 = std::min(Name[cursor] - 'A', 1+'Z'-Name[cursor]);
    copy[cursor] = Name[cursor];
    sum += next1;
    int save = cursor;
    
    if (copy == Name) {
        Answer = std::min(Answer, sum);
        return;
    }
    
    // 오른
    int r = findRight(Name, copy, cursor);
    cursor += r;
    cursor %= N;
    copy[cursor] = Name[cursor];
    // sum += r;
    DFS(n+1, sum+r, copy, cursor);
    copy[cursor] = 'A';
    cursor = save;
    
    
    // 왼
    int l = findLeft(Name, copy, cursor);
    cursor -= l;
    cursor += copy.size();
    cursor %= N;
    copy[cursor] = Name[cursor];
    // sum += l;
    DFS(n+1, sum+l, copy, cursor);
}

int solution(std::string name) {
    N = name.size();
    Name = name;
    
    std::string copy = "";
    for (int i = 0; i < N; i++) {
        copy += "A";
    }
    
    DFS(0, 0, copy, 0);
    
    return Answer;
}

// A B C D E
// F G H E J
// K L M N O
// P Q R S T
// U V W X Y Z