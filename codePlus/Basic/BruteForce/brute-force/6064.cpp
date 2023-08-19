// 2023.8.18 15:00 - 19:02
#include <iostream>

int main(int argc, char* argv[]) {
    int T, M, N, x, y;
    std::cin >> T;
    for (int k = 0; k < T; k++) {
        std::cin >> M >> N >> x >> y;
        // M이 더 작을 때
        if (M < N) {
            int i = x, j = x, first_j = x;
            int count = x, gap = N-M;
            int find = 0;
            do {
                if (j == y) {
                    find = 1;
                    std::cout << count << "\n";
                    break;
                }
                if (j-gap <= 0) {
                    j = j+N-gap;
                } else {
                    j -= gap;
                }
                count+=M;
            } while (j != first_j);
            if (!find) std::cout << -1 << "\n";
        } else if (M > N) {
            int i = y, j = y, first_i = y;
            int count = y, gap = M-N;
            int find = 0;
            do {
                if (i == x) {
                    find = 1;
                    std::cout << count << "\n";
                    break;
                }
                if (i-gap <= 0) {
                    i = i+M-gap;
                } else {
                    i -= gap;
                }
                count+=N;
            } while (i != first_i);
            if (!find) std::cout << -1 << "\n";
        } else {
            if (x != y || x > M || y > N) std::cout << -1 << "\n";
            else std::cout << x << "\n";
        }
        /*
        int now_x = 1, now_y = 1;
        int count = 1;
        int find = 0;
        while(now_x != M || now_y != N) {
            if (now_x == x && now_y == y) {
                find = 1;
                std::cout << count << "\n";
                break;
            }
            if (now_x+1 > M) now_x = 1;
            else now_x++;
            if (now_y+1 > N) now_y = 1;
            else now_y++;
            count++;
        }
        if (now_x == M && now_y == N) {
            if (now_x == x && now_y == y) {
                find = 1;
                std::cout << count << "\n";
            }
        }
        if (!find) std::cout << -1 << "\n";
        */
    }

    return 0;
}
