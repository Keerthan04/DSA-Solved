class Solution {
public:
    int lessequaltok(vector<int>& nums,int goal){
        if(goal < 0)
        return 0;//since minus of function the goal - 1 we are doing os if goal is 0 then to avoid that we are doing this

        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        while(r < n){
        sum += nums[r];

        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        ans += (r-l+1);
        r++;
        }
        return ans;
        
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessequaltok(nums,goal)-lessequaltok(nums,goal-1);
    }
};