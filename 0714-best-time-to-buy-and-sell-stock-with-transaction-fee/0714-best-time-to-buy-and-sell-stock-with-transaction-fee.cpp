class Solution {
public:
    int solve(int ind,int buy,vector<int>&prices,vector<vector<int>> &dp,int &fee){
        if(ind==prices.size()) return 0;//last meaning cant do anything
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            //we can buy so
            dp[ind][buy] = max(-prices[ind]+solve(ind+1,0,prices,dp,fee),solve(ind+1,1,prices,dp,fee));
        }
        else{
            //i cant buy shd sell only
            dp[ind][buy] = max((prices[ind]-fee)+solve(ind+1,1,prices,dp,fee),solve(ind+1,0,prices,dp,fee));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));//index and buy(0 and 1) so dp[n][2]
        return solve(0,1,prices,dp,fee);
    }
};