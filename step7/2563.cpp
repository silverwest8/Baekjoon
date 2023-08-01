#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    vector<vector<int>> xy(100, vector<int>(100));
    int N, x, y, total = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int p = x; p < x + 10; p++) {
            for (int q = y; q < y + 10; q++) {
                if (xy[p][q] == 0) {
                    xy[p][q] = 1;
                }
            }
        }
    }

    for (int p = 0; p < 100; p++) {
        for (int q = 0; q < 100; q++) {
            if (xy[p][q] == 1) {
                total++;
            }
        }
    }

    cout << total;

    return 0;
}

// int main(int argc, char* argv[]) {
//     int N, x_old = -1, y_old= -1, x_new = 0, y_new = 0, total = 0;
//     vector<pair<int, int>> xy;
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         cin >> x_new >> y_new;

//         for (int j = 0; j < xy.size(); j++) {
//             if (xy[j].first < x_new && x_new < xy[j].first + 10) {
//                 if (xy[j].second < y_new && y_new < xy[j].second + 10) {
//                     total -= ((x_new) - (xy[j].first))*((y_new) - (xy[j].second));
//                 } else if (y_new < xy[j].second && xy[j].second < y_new + 10) {
//                     total -= ((x_new) - (xy[j].first))*((y_new + 10) - (xy[j].second));
//                 }
//             } else if (x_new < xy[j].first && xy[j].first < x_new + 10) {
//                 if (xy[j].second < y_new && y_new < xy[j].second + 10) {
//                     total -= ((x_new + 10) - (xy[j].first))*((y_new) - (xy[j].second));
//                 } else if (y_new < xy[j].second && xy[j].second < y_new + 10) {
//                     total -= ((x_new + 10) - (xy[j].first))*((y_new + 10) - (xy[j].second));
//                 }
//             }
//         }

//         if (xy.size()) {
//             if (x_old < x_new && x_new < x_old + 10) {
//                 if (y_old < y_new && y_new < y_old + 10) {
//                     total -= ((x_new) - (x_old))*((y_new) - (y_old));
//                 } else if (y_new < y_old && y_old < y_new + 10) {
//                     total -= ((x_new) - (x_old))*((y_new + 10) - (y_old));
//                 }
//             } else if (x_new < x_old && x_old < x_new + 10) {
//                 if (y_old < y_new && y_new < y_old + 10) {
//                     total -= ((x_new + 10) - (x_old))*((y_new) - (y_old));
//                 } else if (y_new < y_old && y_old < y_new + 10) {
//                     total -= ((x_new + 10) - (x_old))*((y_new + 10) - (y_old));
//                 }
//             }
//         } else {
//             x_old = x_new;
//             y_old = y_new;
//         }
//         xy.push_back(pair<int, int>(x_new, y_new));
//         total += 100;
//     }

//     cout << total;
//     return 0;
// }