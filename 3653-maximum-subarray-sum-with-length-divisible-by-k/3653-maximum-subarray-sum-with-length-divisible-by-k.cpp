class Solution {
public:
    //kadanes using chunks of k we do
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> ps(1);
        for (int n : nums)
            ps.push_back(ps.back() + n);
        // have a prefix sum subarray to get sum of the subarray
        long long res = LLONG_MIN;
        for (int p = 0; p < k; ++p) {
            //each as offset to get the block of length divisible by k we do this
            //for k = 3 we start with 0,1,2 to conisder all block like 0 to 3,0to 6... and 1 to 4,1 to 7 like that  anything after k will be taken by itself as each block sum we take but max start points are from here only so taken like this
            long long sum = 0;
            //for each do kadanes algo
            for (int i = p; i + k <= nums.size(); i += k) {
                //go through each k blocks
                long long n = ps[i + k] - ps[i];
                //for each get the sum of that block
                sum = max(n, sum + n);
                //kadnaes rec where either that k block ka sum or previous blocks + this block ka sum whichever is maximum take that
                res = max(res, sum);
                //then max over result
            }
        }
        return res;
    }
};
