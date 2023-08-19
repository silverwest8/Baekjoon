#include <iostream>
#include <vector>
#include <algorithm>

struct sub {
    std::string name;
    int people;
    int limit;
    float compet;
};

bool compare(sub &a, sub &b) {
    return a.compet > b.compet;
}

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
    /*
    // 8/16
    std::vector<sub> Sub = {
        {"소공개", 71, 29, 0},
        {"황프언", 28, 30, 0},
        {"타프언", 28, 30, 0},
        {"인지개", 26, 30, 0},
        {"데베프", 60, 50, 0},
        // {"문해", 19, 8, 0},
        {"기학원", 27, 35, 0},
        // {"이실리", 22, 15, 0},
        // {"윤실리", 45, 15, 0},
        {"앙트레", 87, 60, 0},
    };
    */
    // 8/18
    std::vector<sub> Sub = {
        {"소공개", 75, 29, 0},
        {"데베프", 62, 50, 0},
        {"타프언", 29, 30, 0},
        {"인지개", 28, 30, 0},
        // {"문해", 22, 8, 0},
        {"기학원", 27, 35, 0},
        // {"이실리", 72, 15, 0},
        // {"윤실리", 52, 15, 0},
        {"황프언", 34, 30, 0},
        {"앙트레", 96, 60, 0},
    };
    for (int i = 0; i < Sub.size(); i++) {
        Sub[i].compet = (float)Sub[i].people / Sub[i].limit;
    }
    std::sort(Sub.begin(), Sub.end(), compare);
    for (int i = 0; i < Sub.size(); i++) {
        std::cout << Sub[i].name << "\t" << Sub[i].compet << "\t(" << Sub[i].people << "/" << Sub[i].limit << ")\n";
    }
    return 0;
}