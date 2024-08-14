class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> answers;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0])
        {
            //left part
            answers.push_back(intervals[i]);
            i++;
        }
        //overlapping now
        while(i<n && intervals[i][0]<=newInterval[1]){
            //min and max go on doing till not overlap then add
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        answers.push_back(newInterval);
        while(i<n){
            //right part
            answers.push_back(intervals[i]);
            i++;
        }
        return answers;
    }
};