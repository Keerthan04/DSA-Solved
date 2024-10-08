class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int m = (right+left)/2;
            if(nums[m]<nums[right]){
                right=m;
            }
            else{
                left = m+1;
            }
        }
        return nums[left];
    }
};