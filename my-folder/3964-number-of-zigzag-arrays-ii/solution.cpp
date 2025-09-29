#include <vector>

using std::vector;

class Solution {
private:
    const int MOD = 1000000007;

    struct Matrix {
        int size;
        vector<vector<long long>> mat;

        Matrix(int s) : size(s), mat(s, vector<long long>(s, 0)) {}
    };

    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix result(A.size);
        for (int i = 0; i < A.size; ++i) {
            for (int j = 0; j < A.size; ++j) {
                for (int k = 0; k < A.size; ++k) {
                    result.mat[i][j] = (result.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix power(Matrix A, long long exp) {
        Matrix result(A.size);
        for (int i = 0; i < A.size; ++i) {
            result.mat[i][i] = 1;
        }
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = multiply(result, A);
            }
            A = multiply(A, A);
            exp /= 2;
        }
        return result;
    }

    vector<long long> multiply_vector(const Matrix& A, const vector<long long>& v) {
        vector<long long> result(A.size, 0);
        for (int i = 0; i < A.size; ++i) {
            for (int j = 0; j < A.size; ++j) {
                result[i] = (result[i] + A.mat[i][j] * v[j]) % MOD;
            }
        }
        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) {
            return r - l + 1;
        }

        int R = r - l + 1;
        int S = 2 * R;

        vector<long long> v2(S);
        for (int i = 0; i < R; ++i) {
            v2[i] = i;
            v2[i + R] = (R - 1) - i;
        }

        Matrix T(S);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < R; ++j) {
                if (j < i) {
                    T.mat[i][j + R] = 1;
                }
                if (j > i) {
                    T.mat[i + R][j] = 1;
                }
            }
        }

        if (n == 2) {
             long long total = 0;
             for(long long count : v2) total = (total + count) % MOD;
             return static_cast<int>(total);
        }

        Matrix T_final = power(T, n - 2);
        vector<long long> vn = multiply_vector(T_final, v2);

        long long total_count = 0;
        for (long long count : vn) {
            total_count = (total_count + count) % MOD;
        }

        return static_cast<int>(total_count);
    }
};
