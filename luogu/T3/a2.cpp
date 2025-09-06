#include<iostream>

using namespace std;

typedef long long ll;
const int N = 21;

bool ban[N][N] = {false};
ll map[N][N];

int nx[8] = {2,1,-1,-2,-2,-1,1,2};
int ny[8] = {1,2,2,1,-1,-2,-2,-1};

int main(void) {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    ban[x2][y2] = true;
    for(int i =0;i<8;i++){
        int fx = x2+nx[i];
        int fy = y2+ny[i];
        if(fx>=0&&fx<=x1&&fy>=0&&fy<=y1){
            ban[fx][fy] = true;
        }
    }

    if(!ban[0][0]) map[0][0] = 1;

    //给y轴赋值
    for(int i = 1;i<=y1;i++){
        if(!ban[0][i]) {
            map[0][i] = map[0][i-1];
        }
    }

    //给x轴赋值
    for(int i =1;i<=x1;i++) {
        if(!ban[i][0]){
            map[i][0] = map[i-1][0];
        }
    }

    //现在让我们来遍历除去边缘区域
    for(int i = 1;i<=x1;i++) {
        for(int j = 1;j<=y1;j++) {
             if(!ban[i][j]) {
                 map[i][j] = map[i-1][j]  + map[i][j-1];
             }   
        }
    }
    cout<<map[x1][y1];
    return 0;
}