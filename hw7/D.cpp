#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int MOD = 1e9 + 7;

struct Matrix {
    int mat[3][3];
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    Matrix operator*(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix matrix_exponentiation(Matrix mat, int power) {
    Matrix ret;
    for (int i = 0; i < 3; ++i) ret.mat[i][i] = 1;
    
    while (power) {
        if (power & 1) ret = ret * mat;
        mat = mat * mat;
        power >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, a, b, c, f_0, f_1;
    cin >> n >> a >> b >> c >> f_0 >> f_1;
    
    if (n == 1) {
        cout << f_0 % MOD << endl;
        return 0;
    }
    if (n == 2) {
        cout << f_1 % MOD << endl;
        return 0;
    }
    
    Matrix T;
    T.mat[0][0] = a; T.mat[0][1] = b; T.mat[0][2] = c;
    T.mat[1][0] = 1; T.mat[1][1] = 0; T.mat[1][2] = 0;
    T.mat[2][0] = 0; T.mat[2][1] = 0; T.mat[2][2] = 1;
    
    Matrix T_n_minus_1 = matrix_exponentiation(T, n - 1);
    
    int f_n = (T_n_minus_1.mat[0][0] * f_1 + T_n_minus_1.mat[0][1] * f_0 + T_n_minus_1.mat[0][2]) % MOD;
    cout << f_n << endl;

    // system("pause");
    return 0;
}
