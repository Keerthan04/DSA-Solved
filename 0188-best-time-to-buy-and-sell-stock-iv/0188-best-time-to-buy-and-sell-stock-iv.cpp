class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>>&dp){
        if(cap==0) return 0;//cant get anything from the market
        if(ind==prices.size()) return 0;//cant get anything from market
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            //can buy so
            dp[ind][buy][cap] = max(-prices[ind] + solve(ind+1,0,cap,prices,dp),solve(ind+1,1,cap,prices,dp));
        }
        else{
            //shd sell
            dp[ind][buy][cap] = max(prices[ind]+ solve(ind+1,1,cap-1,prices,dp),solve(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));//is a 3d dp
        return solve(0,1,k,prices,dp); 
    }
};