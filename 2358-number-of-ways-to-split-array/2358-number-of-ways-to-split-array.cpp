class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = std::accumulate(nums.begin(), nums.end(),
                                             0LL); // Calculate total sum
        long long leftSum = 0;
        int ways = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i]; // Update left sum
            if (leftSum >= totalSum - leftSum) {
                ++ways; // Increment ways if condition is met
            }
        }
        return ways;
    }
};