class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0,r=0;int maxLen=0;
        while(r<nums.size()){
            
            if(nums[r]==0 && k==0){
                //all flips have been done
                while(nums[l]!=0){
                    l++;
                }
                l++;
            }
            else if(nums[r]==0 && k!=0){
                k--;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};