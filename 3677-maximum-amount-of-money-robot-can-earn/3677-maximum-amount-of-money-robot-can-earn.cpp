class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&coins,
              vector<vector<vector<int>>>&dp,int neut,int m,int n){
        if (dp[i][j][neut] != INT_MIN) return dp[i][j][neut];

        // Base case: starting cell
        if (i == 0 && j == 0) {
            int val = coins[0][0];
            int best = val;                 // don't neutralize
            if (val < 0 && neut > 0) best = max(best, 0); // or neutralize
            return dp[i][j][neut] = best;
        }

        int val = coins[i][j];
        int best = INT_MIN;

        // From left
        if (j > 0) {
            // Option A: don't neutralize current cell
            int prev = solve(i, j-1, coins, dp, neut, m, n);
            if (prev != INT_MIN) best = max(best, prev + val);

            // Option B: neutralize current negative cell (if possible)
            if (val < 0 && neut > 0) {
                int prev2 = solve(i, j-1, coins, dp, neut-1, m, n);
                if (prev2 != INT_MIN) best = max(best, prev2 + 0);
            }
        }

        // From up
        if (i > 0) {
            // Option A: don't neutralize current cell
            int prev = solve(i-1, j, coins, dp, neut, m, n);
            if (prev != INT_MIN) best = max(best, prev + val);

            // Option B: neutralize current negative cell (if possible)
            if (val < 0 && neut > 0) {
                int prev2 = solve(i-1, j, coins, dp, neut-1, m, n);
                if (prev2 != INT_MIN) best = max(best, prev2 + 0);
            }
        }

        return dp[i][j][neut] = best;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int neut = 2; // at most 2 neutralizations
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(neut+1, INT_MIN))
        );
        return solve(m-1, n-1, coins, dp, neut, m, n);
    }
};

//can have -ve so hold INT_MIN, and since each state depends upon neut also so 3d dp
//when we neutralize we shd put 0 that is not given 
//the -ve cell we can neutralize or not neutralize also so that also is there