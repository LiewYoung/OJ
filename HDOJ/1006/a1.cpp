
#include<iostream>
#include<cmath>

using namespace std;
/* TLE */
int main(void) {
    int D;
    double speed_s = 6;
    double speed_m = 0.1;
    double speed_h = 1/120.0;
    double distance_s = 0;
    double distance_m = 0;
    double distance_h = 0;
    /*Who is happy? Not me!*/
    while(true) {
        cin >> D;
        if(D == -1) break;
        int sec = 0;
        while(abs(distance_h - 360) > 1e-9) {
            
            distance_s += speed_s;
            if(distance_s == 360) 
            {
              distance_s = 0;
              distance_m += speed_m;
            }

            if(distance_m == 360) 
            {
              distance_m = 0;
              distance_h += speed_h;
            }
            
            if(abs(distance_s - distance_m) > D && abs(distance_m - distance_h) > D && abs(distance_h - distance_s) > D){
                sec++;
            }
        }
        printf("%.3lf\n", sec / (12.0*60.0*60.0));
    }
    return 0;
}