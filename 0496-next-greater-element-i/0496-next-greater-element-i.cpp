class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> nge(nums1.size()); // Fix: Ensure correct size

        // Traverse nums2 in reverse to find next greater elements
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top(); // Fix: Handle empty stack case
            st.push(nums2[i]);
        }

        // Map elements of nums1 to their next greater element in nums2
        for(int i = 0; i < nums1.size(); i++) {
            nge[i] = mp[nums1[i]]; // Fix: Directly assign from the map
        }

        return nge;
    }
};
