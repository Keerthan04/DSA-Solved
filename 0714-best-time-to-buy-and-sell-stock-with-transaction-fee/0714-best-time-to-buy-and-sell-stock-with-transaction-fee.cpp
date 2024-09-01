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
        vector<vector<int>> dp(n+1,vector<int>(2,0));//n+1 as ind==n is bc in this
        dp[n][0] = 0;dp[n][1] = 0;//so base case
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j] = max((prices[i]-fee)+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];//as ind=0 and buy=1 is start
    }
};