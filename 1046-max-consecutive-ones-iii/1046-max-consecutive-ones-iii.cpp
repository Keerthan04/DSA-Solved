class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxones = 0; int maxlen = 0;
        int wstart = 0;
        for(int wend = 0;wend<nums.size();wend++){
            if(nums[wend]==1) maxones++;
            if(wend-wstart+1 - maxones > k){
                if(nums[wstart]==1)maxones--;
                wstart++;
            }
            maxlen = max(maxlen,wend-wstart+1);
        }
        return maxlen;
    }
};