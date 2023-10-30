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
        // std::cout << "cursor : " << cursor << "\n";
        count++;
        // std::cout << "count : " << count << "\n";
    }
    return count;
}

void DFS(int n, int sum, std::string copy, int cursor) {
    
    int next1 = std::min(Name[cursor] - 'A', 1+'Z'-Name[cursor]);
    copy[cursor] = Name[cursor];
    sum += next1;
    // std::cout << cursor << " " << copy << " " << sum << "\n";
    int save = cursor;
    
    if (copy == Name) {
        Answer = std::min(Answer, sum);
        // std::cout << "Same! answer is " << Answer << " in " << Answer << " and " << sum << "\n";
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
    
    // std::cout << "back - " << cursor << " " << sum << "\n";
    
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
    int answer = 0;
    N = name.size();
    Name = name;
    
    
    std::string copy = "";
    std::string copy2 = "";
    for (int i = 0; i < N; i++) {
        copy += "A";
        copy2 += "A";
    }
    // std::cout << copy << " " << copy2 << "\n";
    
    DFS(0, 0, copy, 0);
    /*
    int cursor = 0;
    
    int temp1 = 0;
    int next1 = std::min(name[0] - 'A', 1+'Z'-name[0]);
    copy[0] = name[0];
    temp1 += next1;
    // std::cout << copy << "\n";
    while(name != copy) {
        int l = findLeft(name, copy, cursor);
        int r = findRight(name, copy, cursor);
        
        // if (r < 1) break;
        // std::cout << r << "\n";
        if (l <= r) {
            cursor -= l;
            cursor += N;
            cursor %= N;
            temp1 += l;
        } else {
            cursor += r;
            cursor += N;
            cursor %= N;
            temp1 += r;
        }
        next1 = std::min(name[cursor] - 'A', 1+'Z'-name[cursor]);
        copy[cursor] = name[cursor];
        temp1 += next1;
        
        // std::cout << copy << " " << temp1 << "\n";
    }
    
    
    // std::cout << "\n\n";
    
    cursor = 0;
    int temp2 = 0;
    int next2 = std::min(name[0] - 'A', 1+'Z'-name[0]);
    copy2[0] = name[0];
    temp2 += next2;
    // std::cout << copy2 << "\n";

    while(name != copy2) {
        int l = findLeft(name, copy2, cursor);
        int r = findRight(name, copy2, cursor);
        
        if (l < r) {
            cursor -= l;
            cursor += N;
            cursor %= N;
            temp2 += l;
        } else {
            cursor += r;
            cursor += N;
            cursor %= N;
            temp2 += r;
        }
        next2 = std::min(name[cursor] - 'A', 1+'Z'-name[cursor]);
        copy2[cursor] = name[cursor];
        temp2 += next2;
        // std::cout << l << "\n";
        // std::cout << copy2 << " " << temp2 << "\n";
    }
    
    answer = std::min(temp1, temp2);
    */

    return Answer;
}

// A B C D E
// F G H E J
// K L M N O
// P Q R S T
// U V W X Y Z