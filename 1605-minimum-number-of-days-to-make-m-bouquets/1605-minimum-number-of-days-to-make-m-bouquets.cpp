class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long n = bloomDay.size();
        // Edge case where we can't form the required bouquets
        if ((long)m * k > n) return -1;

        long r = *max_element(bloomDay.begin(), bloomDay.end());
        long l = 1;
        long ans = -1;

        while (l <= r) {
            long mid = l + (r - l) / 2;
            // mid is the number of days we are checking
            long count = 0; // to count the number of flowers in the current bouquet
            long bouquets = 0; // to count the number of bouquets formed

            for (long i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    count++;
                    if (count == k) {
                        bouquets++;
                        count = 0; // reset for the next bouquet
                    }
                } else {
                    count = 0; // reset if the flower hasn't bloomed within mid days
                }
            }

            if (bouquets >= m) {
                ans = mid;
                r = mid - 1; // try to find a smaller possible value
            } else {
                l = mid + 1; // increase the number of days
            }
        }
        return ans;
    }
};
