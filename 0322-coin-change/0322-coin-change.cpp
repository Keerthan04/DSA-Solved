class Solution {
public:
    int solve(int index, int target, vector<int> &coins, vector<vector<int>>& dp) {
        // Base Case: when only one type of coin is considered
        if (index == 0) {
            if (target % coins[index] == 0) return target / coins[index];
            else return 1e9; // Represents an impossible state
        }

        // Memoization check
        if (dp[index][target] != -1) return dp[index][target];

        // Not taking the current coin
        int notTake = solve(index - 1, target, coins, dp);

        // Taking the current coin
        int take = 1e9; // Initialize with a large number
        if (coins[index] <= target) 
            take = 1 + solve(index, target - coins[index], coins, dp);
        //so if infinte supply always will have take mai index only as we can take it again so
        //also here 1+ we did as it is that we take 1 coin and then do so
        // Store the result in dp table
        return dp[index][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(n - 1, amount, coins, dp);
        //whenever they ask like the if not found and all do this
        // If result is 1e9 or more, no valid combination was found
        return result >= 1e9 ? -1 : result;
    }
};
