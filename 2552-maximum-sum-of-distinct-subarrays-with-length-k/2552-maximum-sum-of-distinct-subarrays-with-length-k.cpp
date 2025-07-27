class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long maxSum = 0;
        unordered_map<int, int> freq;
        int wstart = 0;

        for(int wend = 0; wend < nums.size(); wend++) {
            //do what we need to do in the end part here
            sum += nums[wend];//each from right add 
            freq[nums[wend]]++;//add to freq

            if (wend >= k - 1) {
                //this is part where we attain the subarray so do work here
                if (freq.size() == k) {
                    //if any condition type then here we do condtition and actual work
                    //here see if we have unique ele only then find sum
                    maxSum = max(sum, maxSum);
                }

                // Remove wstart element from freq map
                freq[nums[wstart]]--;
                if (freq[nums[wstart]] == 0) {
                    freq.erase(nums[wstart]);
                    //only if freq is 0 we renive
                }

                ///remove the start and from sum
                sum -= nums[wstart];
                wstart++;
            }
        }

        return maxSum;
    }
};
//this is the basic template for the sliding window with fixed k side
/*
for (int wend = 0; wend < nums.size(); wend++) {
    // Add the end element
    <update window state with nums[wend]>

    if (wend >= k - 1) {
        // Window of size k formed
        <check condition on window>
        <update result if needed>

        // Remove the start element
        <undo effect of nums[wstart]>
        wstart++;
    }
}

*/
