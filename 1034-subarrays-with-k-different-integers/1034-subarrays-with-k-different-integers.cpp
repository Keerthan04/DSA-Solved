class Solution {
public:
    int lessthank(vector<int> nums, int k){
        int l=0,r=0;
        unordered_map<int,int> mpp;
        int cnt = 0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessthank(nums, k) - lessthank(nums, k-1);
    }
};
