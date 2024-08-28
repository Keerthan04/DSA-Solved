class Solution {
public:
    int solve(int index, int target, vector<int> &coins, vector<vector<int>>& dp) {
        // Base Case: when only one type of coin is considered
        if (index == 0) {
            if (target % coins[index] == 0) return 1;
            else return 0; // Represents an impossible state
        }

        // Memoization check
        if (dp[index][target] != -1) return dp[index][target];

        // Not taking the current coin
        int notTake = solve(index - 1, target, coins, dp);

        // Taking the current coin
        int take = 0; // Initialize with a large number
        if (coins[index] <= target) 
            take = solve(index, target - coins[index], coins, dp);
        //so if infinte supply always will have take mai index only as we can take it again so
        //also here 1+ we did as it is that we take 1 coin and then do so
        // Store the result in dp table
        return dp[index][target] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};