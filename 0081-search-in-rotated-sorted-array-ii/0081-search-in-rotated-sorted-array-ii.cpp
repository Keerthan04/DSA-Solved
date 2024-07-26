class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(nums[mid]==target){
                return true;
            }
            if(nums[start]==nums[mid] && nums[mid]==nums[end]){
                //condition which is to be added for extra from the without duplicates part
                start++;end--;continue;
            }
            if(nums[start]>nums[mid]){
                //right side is the sorted side
                if(nums[mid]<=target && target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            else{
                if(nums[start]<=target && target<=nums[mid]){
                    end = mid-1;
                }else{
                    start = mid +1;
                }
            }
        }
        return false;
    }
};