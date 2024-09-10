class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            // all the possible cuts in that block we are seeing how to do
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            // basically the current cut plus the cost of cutting the partitions we calculate
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        // to track the length we did the above part
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(1, m - 2, cuts, dp);
    }
};
