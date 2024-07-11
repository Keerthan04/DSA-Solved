class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea =0;
        int l = 0;
        int r = heights.size()-1;
        while(l<r){
            int distance = r-l;
            int height = min(heights[l],heights[r]);
            maxArea = max(maxArea,height*distance);
            if(heights[l]>heights[r]) r--;
            else l++;
        }
        return maxArea;
    }
};