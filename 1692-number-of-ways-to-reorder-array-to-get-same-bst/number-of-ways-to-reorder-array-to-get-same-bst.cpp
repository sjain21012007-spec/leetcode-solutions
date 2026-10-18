#include <vector>
#include <numeric>

class Solution {
    const int MOD = 1e9 + 7;

      long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r; 
        
        long long num = 1, den = 1;
        for (int i = 1; i <= r; i++) {
            num = (num * (n - r + i)) % MOD;
            den = (den * i) % MOD;
        }
        return num; 
    }

public:
    int numOfWays(std::vector<int>& nums) {
        return (solve(nums) - 1 + MOD) % MOD;
    }

    long long solve(std::vector<int>& v) {
        if (v.size() <= 2) return 1;

        int root = v[0];
        std::vector<int> left, right;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] < root) left.push_back(v[i]);
            else right.push_back(v[i]);
        }

        long long current_combinations = get_combinations(left.size() + right.size(), left.size());
        
        long long left_ways = solve(left);
        long long right_ways = solve(right);
        return (((current_combinations * left_ways) % MOD) * right_ways) % MOD;
    }

private:
    long long get_combinations(int n, int r) {
        static std::vector<std::vector<long long>> pascal;
        if (pascal.empty()) {
            pascal.assign(1001, std::vector<long long>(1001, 1));
            for (int i = 1; i <= 1000; ++i) {
                for (int j = 1; j < i; ++j) {
                    pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
                }
            }
        }
        return pascal[n][r];
    }
};
