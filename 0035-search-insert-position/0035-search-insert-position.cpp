class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid]==target){
                return mid;
            }
            if (nums[mid] < target) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (index == -1)
            return 0;//if index=-1 meaning that first ele and no ceil so shd come at first
        return index+1;
    }
};