class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int start = 0;
        for(int i =1;i<nums.size();i++){
            if(nums[i]!=nums[start]){
                nums[start+1]=nums[i];
                start+=1;
            }
        }
        for(int i=start+1;i<nums.size();i++){
            nums[i]=-1;
        }
        return start+1;
    }
};