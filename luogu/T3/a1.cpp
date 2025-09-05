#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 25;

int n, m, hx, hy;
bool ban[N][N];
ll f[N][N];

/*妙啊，妙蛙种子吃着妙脆角进米奇妙妙屋。真是妙到家了*/
// 8 个日字跳偏移
const int dx[] = {-2,-1,1,2,2,1,-1,-2};
const int dy[] = {1,2,2,1,-1,-2,-2,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> hx >> hy;

    // 1. 标记禁区
    ban[hx][hy] = true;
    for (int i = 0; i < 8; ++i) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            ban[nx][ny] = true;
    }

    // 2. 边界条件
    if (!ban[0][0]) f[0][0] = 1;

    // 第 0 行
    for (int j = 1; j <= m; ++j)
        if (!ban[0][j]) f[0][j] = f[0][j - 1];

    // 第 0 列
    for (int i = 1; i <= n; ++i)
        if (!ban[i][0]) f[i][0] = f[i - 1][0];

    // 3. 递推
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!ban[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];

    cout << f[n][m] << '\n';
    return 0;
}