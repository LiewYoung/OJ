#include <iostream>
using namespace std;

/*这题过于权威了*/
// 矩阵乘法（2x2矩阵）模7
void matMul(long long A[2][2], long long B[2][2], long long mod, long long C[2][2]) {
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod;
}

// 矩阵快速幂
void matPow(long long M[2][2], long long power, long long mod, long long result[2][2]) {
    // 初始化为单位矩阵
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;
    
    long long base[2][2];
    // 复制 M 到 base
    base[0][0] = M[0][0]; base[0][1] = M[0][1];
    base[1][0] = M[1][0]; base[1][1] = M[1][1];

    while (power > 0) {
        if (power % 2 == 1) {
            long long temp[2][2];
            matMul(result, base, mod, temp);
            // 将 temp 复制回 result
            result[0][0] = temp[0][0]; result[0][1] = temp[0][1];
            result[1][0] = temp[1][0]; result[1][1] = temp[1][1];
        }
        long long temp[2][2];
        matMul(base, base, mod, temp);
        // 更新 base
        base[0][0] = temp[0][0]; base[0][1] = temp[0][1];
        base[1][0] = temp[1][0]; base[1][1] = temp[1][1];

        power /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int A, B, n;
        cin >> A >> B >> n;
        if (A == 0 && B == 0 && n == 0) {
            break;
        }

        if (n == 1 || n == 2) {
            // f(1) = 1, f(2) = 1
            cout << 1 << "\n";
            continue;
        }

        // 转换矩阵
        long long M[2][2] = {
            {A % 7, B % 7},
            {1, 0}
        };
        long long resultMatrix[2][2];
        // 计算 M^(n-2)
        matPow(M, n - 2, 7, resultMatrix);

        // 计算 f(n)
        // 初始向量为 [f(2), f(1)] = [1, 1]
        long long fn = (resultMatrix[0][0] * 1 + resultMatrix[0][1] * 1) % 7;

        cout << fn << "\n";
    }

    return 0;
}