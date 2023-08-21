#include <iostream>
// #include <vector>
#include <deque>
#include <string>
#define MAX 1000

int T, K, count = 0;
std::deque<int> v[MAX+1];
std::deque<int> v2[MAX+1];

void rotate(int n, int dir) {
    int temp;
    if (dir == 1) { // 시계 방향
        temp = v[n].back();
        v[n].pop_back();
        v[n].push_front(temp);
    } else if (dir == -1) { // 반시계
        temp = v[n].front();
        v[n].pop_front();
        v[n].push_back(temp);
    }
}

void DFS_left(int num, int dir) {
    if (num-1 < 1) {
        return;
    } else {
        if (v[num-1][2] != v[num][6]) {
            DFS_left(num-1, dir*(-1));
            rotate(num-1, dir*-1);
        }
    }
}

void DFS_right(int num, int dir) {
    if (num+1 > T) {
        return;
    } else {
        if (v[num][2] != v[num+1][6]) {
            DFS_right(num+1, dir*(-1));
            rotate(num+1, dir*-1);
        }
    }
}

// void DFS(int num, int dir) {
//     if (num-1 < 1 || num+1 > T) {
//         return;
//     } else {
//         if (v[num-1][2] != v[num][6]) {
//             DFS(num-1, dir*(-1));
//             rotate(num-1, dir*-1);
//         }
//         if (v[num][2] != v[num+1][6]) {
//             DFS(num+1, dir*(-1));
//             rotate(num+1, dir*-1);
//         }
//     }
// }

int main(int argc, char* argv[]) {
    // N극은 0, S극은 1
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        std::string temp;
            std::cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            v[i].emplace_back(temp[j]-48);
        }
    }
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int num, dir, tmp;
        std::cin >> num >> dir;

        // 왼쪽으로 연쇄
        DFS_left(num, dir);
        // tmp = dir;
        // for (int j = num-1; j >= 1; j--) {
        //     if (v[j][2] == v[j+1][6]) {
        //         // 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전
        //         break;
        //     }
        //     // 반시계 -> 시계 -> 
        //     tmp *= -1;
        //     rotate(j, tmp);
        // }

        // 오른쪽으로 연쇄
        DFS_right(num, dir);
        // tmp = dir;
        // for (int j = num+1; j <= T; j++) {
        //     if (v[j-1][2] == v[j][6]) {
        //         // 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전
        //         break;
        //     }
        //     // 반시계 -> 시계 -> 
        //     tmp *= -1;
        //     rotate(j, tmp);
        // }

        // DFS(num, dir);

        rotate(num, dir);
    }

    for (int i = 1; i <= T; i++) {
        if (v[i][0] == 1) count++;
    }
    std::cout << count;
    return 0;
}