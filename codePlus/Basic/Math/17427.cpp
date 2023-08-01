#include <iostream>

long g(int A) {
    long result = 0;
    for (int i = 1; i <= A; i++) {
        result += i*(A/i);
    }
    
    return result;
}

int main(int argc, char* argv[]) {
    int N;
    long result = 0;
    std::cin >> N;
    
    result = g(N);
    std::cout << result;

    return 0;
}
