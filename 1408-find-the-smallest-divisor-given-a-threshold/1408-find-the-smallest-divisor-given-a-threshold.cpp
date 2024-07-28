class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int r = *max_element(nums.begin(),nums.end());
        int l=1;int ans = -1;
        while(l<=r){
            int mid = l+((r-l)/2);
            int total=0;
            for(int i = 0;i<nums.size();i++){
                total+=ceil((static_cast<double>(nums[i])/mid));
            }
            if(total<=threshold){
                ans = mid;
                r = mid -1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};