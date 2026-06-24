
class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                long long v = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + v * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiply(const Matrix& A,
                               const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    long long zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;

        if (n == 1) return k;

        int m = 2 * k;

        // State:
        // [0..k-1]     -> last comparison is UP
        // [k..2k-1]    -> last comparison is DOWN
        Matrix T(m, vector<long long>(m, 0));

        // newUp[j] = sum of down[i], i < j
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < j; i++) {
                T[j][k + i] = 1;
            }
        }

        // newDown[j] = sum of up[i], i > j
        for (int j = 0; j < k; j++) {
            for (int i = j + 1; i < k; i++) {
                T[k + j][i] = 1;
            }
        }

        // Base vector for length = 2
        vector<long long> vec(m, 0);

        // Up[j] = number of previous values < j
        for (int j = 0; j < k; j++) {
            vec[j] = j;
        }

        // Down[j] = number of previous values > j
        for (int j = 0; j < k; j++) {
            vec[k + j] = k - 1 - j;
        }

        long long p = n - 2;

        // Compute T^(n-2) * vec
        Matrix P(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) P[i][i] = 1;

        Matrix A = T;

        while (p > 0) {
            if (p & 1) P = multiply(P, A);
            A = multiply(A, A);
            p >>= 1;
        }

        vec = multiply(P, vec);

        long long ans = 0;
        for (long long x : vec) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};