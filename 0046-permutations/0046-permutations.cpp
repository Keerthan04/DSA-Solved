class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &intresult,set<int> &map){
        if(nums.size() == intresult.size()){
            ans.push_back(intresult);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //go through all the nums
            if(map.find(nums[i])==map.end()){
                //if ele not in map already only then can use it
                intresult.push_back(nums[i]);
                map.insert(nums[i]);
                solve(nums,ans,intresult,map);
                map.erase(nums[i]);
                intresult.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> intresult;
        set<int> map;
        solve(nums,ans,intresult,map);
        return ans;
    }
};