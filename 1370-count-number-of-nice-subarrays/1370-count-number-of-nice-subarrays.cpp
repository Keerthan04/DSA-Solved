class Solution {
public:
    int lessequaltok(vector<int>& nums,int goal){
        if(goal < 0)
        return 0;//since minus of function the goal - 1 we are doing os if goal is 0 then to   avoid that we are doing this

        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        while(r < n){
        sum += (nums[r]%2);

        while(sum > goal){
            sum -= (nums[l]%2);
            l++;
        }
        ans += (r-l+1);
        r++;
        }
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessequaltok(nums,k)-lessequaltok(nums,k-1);
    }
};