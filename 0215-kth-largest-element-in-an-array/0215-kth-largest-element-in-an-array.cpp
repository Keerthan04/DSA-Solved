class Solution {
public:
    // Function to count numbers greater than or equal to mid
    int countGreaterOrEqual(int mid, vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num >= mid) count++;
        }
        return count;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        while (start <= end) {  // Change to allow correct search space convergence
            int mid = start + (end - start) / 2;
            int large_num = countGreaterOrEqual(mid, nums);

            if (large_num >= k) {
                start = mid + 1;  // Move start to mid + 1 if we have too many large elements
            } else {
                end = mid - 1;  // Move end to mid - 1 if we don't have enough large elements
            }
        }

        // Return the element where the binary search stops
        return end;  // 'end' will point to the correct k-th largest element
    }
};
