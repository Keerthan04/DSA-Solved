class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                // then we need to remove and this is the ele whose area to do
                int element = heights[st.top()];
                st.pop();
                int nse = i;                          // current is the nse
                int pse = st.empty() ? -1 : st.top(); // if empty then -1 else the previous ele of the stack is the pse
                maxArea = max(maxArea, element * (nse - pse - 1));
            }
            st.push(i); // index we put
        }
        // for all the other elements
        while (!st.empty())
        {
            int element = heights[st.top()];
            st.pop();
            int nse = heights.size();             // nse is the last index i.e nth index
            int pse = st.empty() ? -1 : st.top(); // if empty then -1 else the previous ele of the stack is the pse
            maxArea = max(maxArea, element * (nse - pse - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    psum[i][j] = (i == 0) ? 1 : psum[i - 1][j] + 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, largestRectangleArea(psum[i]));
        }

        return maxArea;
    }
};