class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxWeight = 0;
        for (int i : weights) {
            sum += i;
            maxWeight = max(maxWeight, i);
        }
        
        int l = maxWeight, r = sum; // lower bound is max weight, upper bound is sum of all weights
        int ans = sum;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int daysCount = 1; // start with one day
            int total = 0;
            
            for (int i = 0; i < weights.size(); i++) {
                if (total + weights[i] > mid) {
                    daysCount++;
                    total = weights[i];
                } else {
                    total += weights[i];
                }
            }
            
            if (daysCount > days) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        
        return ans;
    }
};
