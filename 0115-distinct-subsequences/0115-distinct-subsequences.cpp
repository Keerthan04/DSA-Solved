class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base conditions
        if (j < 0) return 1;  // Successfully matched all of `t`
        if (i < 0) return 0;  // `s` is exhausted but `t` is not

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            // Two choices: either pick the character `s[i]` and move both `i` and `j`,
            // or skip `s[i]` and just move `i`
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        } else {
            // Character does not match, move `i` only
            return dp[i][j] = solve(i - 1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};
