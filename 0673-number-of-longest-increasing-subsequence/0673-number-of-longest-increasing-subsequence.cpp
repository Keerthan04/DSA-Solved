class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        //initialize bith as n=1
        int maxi =1;
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                if(nums[i]>nums[prev_index]  && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    cnt[i] = cnt[prev_index];//take cnt as it is
                }
                else if(nums[i]>nums[prev_index]  && 1 + dp[prev_index] == dp[i]){
                    //there are alternate ways to get this so
                    cnt[i]+=cnt[prev_index];
                }
            }
            maxi = max(dp[i],maxi);//to track and get the lis length
        }
        int numberOfWays =0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) numberOfWays +=cnt[i];//so add all the cnt having dp ==lis
        }
        return numberOfWays;
    }
};