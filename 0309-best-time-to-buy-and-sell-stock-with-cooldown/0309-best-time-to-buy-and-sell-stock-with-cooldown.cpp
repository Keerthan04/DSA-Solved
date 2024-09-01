class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size()) return 0; // Last meaning can't do anything
        //>= as can go beyond here so
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        if (buy) {
            // We can buy
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, dp), solve(ind + 1, 1, prices, dp));
        } else {
            // We can't buy, so we should sell
            profit = max(prices[ind] + solve(ind + 2, 1, prices, dp), solve(ind + 1, 0, prices, dp));
        }
        
        dp[ind][buy] = profit;
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[n][2] for index and buy (0 or 1)
        return solve(0, 1, prices, dp); // Start with 0 index and 1 indicating we can buy
    }
};
