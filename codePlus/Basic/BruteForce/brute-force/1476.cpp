#include <iostream>

int main(int argc, char* argv[]) {
    int E, S, M, e, s, m, result = 0;
    std::cin >> E >> S >> M;
    e = s = m = 0;
    while(E != e || S != s || M != m) {
        e++;
        s++;
        m++;
        if (e>15) e = 1;
        if (s>28) s = 1;
        if (m>19) m = 1;
        result++;
    }
    
    std::cout << result;

    return 0;
}
