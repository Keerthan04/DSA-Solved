bool comp(vector<int> val1,vector<int> val2){
    //each ele are 1d array
    return val1[1]<val2[1];//based on end time
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;//always one meeting happens
        int freetime = intervals[0][1];//endtime of the first one
        for(int i =1;i<n;i++){
            if(intervals[i][0]>=freetime){
                cnt++;
                freetime = intervals[i][1];//that included so freetime is its endtime
            }
        }
        return n-cnt;
    }
};