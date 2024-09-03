class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp; // dp array to store the smallest end element for each length
        for(int num : nums) {
            // Use binary search to find the first element in dp which is >= num
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if(it == dp.end()) {
                // If no such element found, num extends the largest subsequence
                dp.push_back(num);
            } else {
                // Otherwise, replace the found element with num
                *it = num;
            }
        }
        // The size of dp is the length of the LIS
        return dp.size();
    }
};
