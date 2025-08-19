class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        long long no_of_subsets = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                maxLen = max(maxLen, right - left + 1);
                continue;
            }
            if (maxLen != 0) {
                no_of_subsets += 1LL * maxLen * (maxLen + 1) / 2;
                maxLen = 0;
            }
            left = right + 1;
        }

        // handle case when array ends with zeros
        if (maxLen != 0) {
            no_of_subsets += 1LL * maxLen * (maxLen + 1) / 2;
        }

        return no_of_subsets;
    }
};
