class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = INT_MIN;
        double left = 0;
        double sum = 0;
        for(double right = 0;right<nums.size();right++){
                sum+=nums[right];
                if(right>=k-1){
                    double avg = sum/k;//shd cast as (double)sum/k as sum was int earlier gives me int division so to do double so make one double to get us the double avg else make sum double so whole as double works
                    maxavg = max(maxavg,avg);
                    sum-=nums[left];
                    left++;
                }
        }
        return maxavg;
    }
};