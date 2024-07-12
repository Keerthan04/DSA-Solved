class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int firstOccur=-1,lastOccur=-1;
        if(nums.size()==0) return {-1,-1};
        //getting first occur
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                firstOccur=mid;
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        start=0;
        end=nums.size()-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(target == nums[mid]){
                lastOccur=mid;
                start=mid+1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return {firstOccur,lastOccur};

    }
};