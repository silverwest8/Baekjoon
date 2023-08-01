#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int N, M, temp, max, sum;
    cin >> N >> M;
    vector<int> cards;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());
    max = cards[0] + cards[1] + cards[2];

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                sum = cards[i] + cards[j] + cards[k];
                if (sum > M) {
                    break;
                }
                else if (sum > max) {
                    max = sum;
                }
            }
        }
    }
    cout << max;
    return 0;
}