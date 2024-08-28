class Solution {
public:
    int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTaken = findWaysUtil(ind - 1, target, arr, dp);

        int taken = 0;
        if (arr[ind] <= target)
            taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (notTaken + taken);
    }

    int findWays(vector<int>& num, int target) {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return findWaysUtil(n - 1, target, num, dp);
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for (auto &it : arr)
            totSum += it;

        // If total sum minus difference is negative or odd, return 0
        if (totSum < d || (totSum - d) % 2 != 0)
            return 0;

        int target = (totSum - d) / 2;
        return findWays(arr, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};