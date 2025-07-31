class Solution {
public:
    int search(vector<int> &nums,int target,bool findingLast){
        int keyindex = -1;
        int start = 0; int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(target > nums[mid]) start = mid+1;
            else if(target < nums[mid]) end = mid-1;
            else{
                //then = key it is
                keyindex = mid;
                if(findingLast){
                    //finding last occurence then
                    start = mid+1;
                }else{
                    //finding first so
                    end = mid -1;
                }
            }
        }
        return keyindex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize with two elements
        result[0] = search(nums, target, false); // Find first occurrence
        if (result[0] == -1) return result;      // Not found
        result[1] = search(nums, target, true);  // Find last occurrence
        return result;
    }
};