class Solution {
public:
    bool isAllStars(const string &S1, int i) {
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool wildcardMatchingUtil(const string &S1, const string &S2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
            return isAllStars(S1, i);

        // If the result for this state has already been calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // If the characters at the current positions match or S1 has a '?'
        if (S1[i] == S2[j] || S1[i] == '?')
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        else if (S1[i] == '*')
            // Two options: either '*' represents an empty string or it matches one or more characters in S2
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return dp[i][j] = false;
    }

    bool isMatch(const string &s, const string &p) {
        int n = p.length();
        int m = s.length();

        // Create a DP table to memoize results
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return wildcardMatchingUtil(p, s, n - 1, m - 1, dp);
    }
};