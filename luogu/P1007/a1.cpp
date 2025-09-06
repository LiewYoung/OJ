#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int L, N;
    cin >> L >> N;
    
    int min_time = 0;
    int max_time = 0;
    
    for (int i = 0; i < N; ++i) {
        int pos;
        cin >> pos;
        
        // 最小时间：取离两端最近的距离
        int min_dist = min(pos, L + 1 - pos);
        min_time = max(min_time, min_dist);
        
        // 最大时间：取离两端最远的距离
        int max_dist = max(pos, L + 1 - pos);
        max_time = max(max_time, max_dist);
    }
    
    cout << min_time << " " << max_time << endl;
    return 0;
}