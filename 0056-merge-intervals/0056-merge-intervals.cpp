class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) {
            return intervals;
        }
        
        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        int n = intervals.size();
        
        // Initialize the first interval as the current interval to merge
        vector<int> current = intervals[0];
        
        for(int i = 1; i < n; ++i) {
            // If the current interval overlaps with the next interval, merge them
            if(current[1] >= intervals[i][0]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                // No overlap, so add the current interval to the merged list and update current
                merged.push_back(current);
                current = intervals[i];
            }
        }
        
        // Add the last interval
        merged.push_back(current);
        
        return merged;
    }
};
