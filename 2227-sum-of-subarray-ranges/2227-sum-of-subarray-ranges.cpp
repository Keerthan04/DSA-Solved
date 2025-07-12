class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = 0, minSum = 0;

        // Calculate sum of subarray maximums
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long count = (mid - left) * 1LL * (right - mid);
                maxSum += count * nums[mid];
            }
            st.push(i);
        }

        // Clear the stack before next use
        while (!st.empty()) st.pop();

        // Calculate sum of subarray minimums
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long count = (mid - left) * 1LL * (right - mid);
                minSum += count * nums[mid];
            }
            st.push(i);
        }

        return maxSum - minSum;
    }
};
