#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<string, double> table = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}};
    string subject, grade;
    double point, total = 0, total_point = 0;

    for (int i = 0; i < 20; i++)
    {
        cin >> subject >> point >> grade;
        if (grade != "P") {
            total_point += point;
            total += point * table[grade];
        }
    }
    std::cout << fixed;
    std::cout.precision(9);
    cout << total/total_point;

    return 0;
}