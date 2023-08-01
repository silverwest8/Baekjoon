#include <iostream>

int GCF(int n, int m) { // greatest common factor
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

// int GCF(int n, int m) { // greatest common factor
//     int result, small;
//     small = n;
//     if (m<n) small = m;
//     for (int i = 1; i <= small; i++) {
//         if (n%i == 0 && m%i == 0) {
//             result = i;
//         }
//     }
//     return result;
// }

int LCM(int n, int m) { // least common multiple
    int result, gcn;
    gcn = GCF(n, m);
    result =  n * m / gcn;
    return result;
}

int main(int argc, char* argv[]) {

    int N, M, i, j;
    std::cin >> N >> M;

    std::cout << GCF(N, M) << "\n" << LCM(N, M);

    return 0;
}
