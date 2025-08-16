class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++) mp[nums[i]]++;
        int maxFreq = 0;
        for(auto &it:mp) maxFreq = max(maxFreq,it.second);
        //now we use this maxFreq as the dp and find for each dp[i] no of rounds needed to reduce this to 0 so then for all the freq in map we can add the values and return
        const int INF = 1e9;
        vector<int> dp(maxFreq+1,INF);
        dp[0] = 0;//if freq is 0 then 0 rounds
        dp[1] = INF;//if 1 then we cant as we can only do of 2 and 3
        if(maxFreq >=2)dp[2] = 1;//if freq is 2 then direct to 0 so 1 round
        if(maxFreq >=3)dp[3] = 1;//similar to the dp[2] case
        for(int i =4;i<=maxFreq;i++){
            //now for each i we can reduce to i-2 or i-3 in one round
            if(dp[i-2]!=INF) dp[i] = min(dp[i],dp[i-2]+1);//if INF then not valid so
            if(dp[i-3]!=INF) dp[i] = min(dp[i],dp[i-3]+1);
        }
        int rounds = 0;
        for(auto it:mp){
            //now go through all the freq and then find the rounds for it
            if(dp[it.second] == INF) return -1;
            rounds+=dp[it.second];
        }
        return rounds;
    }    
};