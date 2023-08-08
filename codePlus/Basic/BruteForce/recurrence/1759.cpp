#include <iostream>
#include <vector>
#include <algorithm>
#define max 15

int L, C;
char before = 0;
std::vector<char> v(max+1);
std::vector<char> v2(max+1);
std::vector<bool> visited(max+1, false);

void dfs(int depth) {
    int vowel = 0, consonant = 0;
    if (depth == L) {
        for (int i = 0; i < L; i++) {
            if (v2[i] == 'a' || v2[i] == 'e' || v2[i] == 'i' || v2[i] == 'o' || v2[i] == 'u') vowel++;
            else consonant++;
        }
        if (vowel >= 1 && consonant >=2) {
            // 여기 L을 C로 써서... 삽질
            for (int i = 0; i < L; i++) {
                std::cout << v2[i];
            }
            std::cout << "\n";
        }
    } else {
        for (int i = depth; i < C; i++) {
            if (!visited[i] && before < v[i]) {
                visited[i] = true;
                v2[depth] = v[i];
                dfs(depth+1);
                before = v[i];
                visited[i] = false;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    char temp;
    std::cin >> L >> C;
    for (int i = 0; i < C; i++) {
        std::cin >> temp;
        v[i] = temp;
    }
    std::sort(v.begin(), v.begin()+C);
    dfs(0);
    return 0;
}