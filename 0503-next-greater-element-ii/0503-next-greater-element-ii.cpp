class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> nge(N, -1); // Fix: Ensure correct size initialization imp
        stack<int> st;

        // Iterate twice the length to handle circular array
        for(int i = 2 * N - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % N]) {
                st.pop();
            }
            if(i < N) { // Only assign for the first N elements
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % N]);
        }
        return nge;
    }
};
