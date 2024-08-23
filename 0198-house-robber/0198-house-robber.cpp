int solve(vector<int>& dp, vector<int>& nums, int n) {
    if (n < 0) return 0; // If there are no houses to rob, return 0
    if (dp[n] != -1) return dp[n]; // Return the cached result

    // Either rob the current house and move to n-2, or skip the current house
    int robCurrent = nums[n] + solve(dp, nums, n - 2);
    int skipCurrent = solve(dp, nums, n - 1);

    // Cache the result in dp and return it
    return dp[n] = max(robCurrent, skipCurrent);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(dp, nums, n - 1);
    }
};
