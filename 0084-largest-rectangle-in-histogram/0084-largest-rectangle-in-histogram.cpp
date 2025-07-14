class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                //then we need to remove and this is the ele whose area to do
                int element = heights[st.top()];st.pop();
                int nse = i;//current is the nse
                int pse = st.empty()? -1: st.top();//if empty then -1 else the previous ele of the stack is the pse
                maxArea = max(maxArea,element*(nse-pse-1));
            }
            st.push(i);//index we put
        }
        //for all the other elements
        while(!st.empty()){
            int element = heights[st.top()];st.pop();
            int nse = heights.size();//nse is the last index i.e nth index
            int pse = st.empty()? -1: st.top();//if empty then -1 else the previous ele of the stack is the pse
            maxArea = max(maxArea,element*(nse-pse-1));
        }
        return maxArea;
    }
};