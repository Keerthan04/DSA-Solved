class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //given each array is ascending so easily we can get that the max and min are 1st and last ele of the array so greedy
        int res=0;
        //take the min and max of the first one then iterate on the others 
        int cur_min = arrays[0][0];
        int cur_max = arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            //so as range then we see the max of the next array max and min of prev(cur_min) else the max of prec(cur_max) and the min of next so once done then updation of the cur_min and max is done and then the range is done 
            res = max(res, max(arrays[i].back() - cur_min, cur_max - arrays[i][0]));
                //max then shd be passed like this as it takes only 2 so like this 
            cur_min = min(cur_min,arrays[i][0]);
            cur_max = max(cur_max,arrays[i].back());
        }
        return res;
    }
};