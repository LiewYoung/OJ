
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double D;
    while (cin >> D) {
        if (D == -1) break;
        if (D >= 120) {
            cout << "0.000" << endl;
            continue;
        }
        double totalSecondsInDay = 86400.0;
        double happyTime;
        if (D <= 90) {
            happyTime = (2.0 / 3.0) * (360 - 2 * D) * (360 - 4 * D);
        } else {
            happyTime = 0.0;
        }
        double percentage = (happyTime / totalSecondsInDay) * 100.0;
        cout << fixed << setprecision(3) << percentage << endl;
    }
    return 0;
}