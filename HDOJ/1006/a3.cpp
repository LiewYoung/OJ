#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double D;
    double speed_s = 6.0;
    double speed_m = 0.1;
    double speed_h = 1.0 / 120.0;
    while(true) {
        cin>>D;
        if(D == -1) break;
        if(D >= 120) {
            printf("0.000\n");
            continue;
        }else if(D == 0) {
            printf("100.000\n");
            continue;
        }else {
            
        }
    }
}