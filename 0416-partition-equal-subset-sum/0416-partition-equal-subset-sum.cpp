bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    
    // Initialize the first column, since a sum of 0 can always be achieved with an empty subset
    for(int i = 0; i < n; i++) 
        dp[i][0] = true;

    // Handle the first row separately, only if the first element is within the sum range
    if(arr[0] <= sum) 
        dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= sum; target++) {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) 
                take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    
    return dp[n-1][sum];
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) 
            sum += nums[i];

        // Check if the sum is odd; if yes, it cannot be partitioned into two equal subsets
        if(sum % 2 != 0) 
            return false;

        // Use the isSubsetSum function to determine if there's a subset with sum equal to sum/2
        return isSubsetSum(nums, sum / 2);
    }
};