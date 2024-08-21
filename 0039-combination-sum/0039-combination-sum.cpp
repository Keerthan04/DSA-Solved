bool isSolved(vector<int> &ans,int target){
    int sum = accumulate(ans.begin(), ans.end(), 0);  // Initialize sum to 0
    return sum == target;
}
bool isValid(vector<int> &ans,int target,int k){
    int sum = accumulate(ans.begin(), ans.end(), 0);  // Initialize sum to 0
    return (sum + k) <= target;  // Ensure the sum does not exceed the target
}
void solve(vector<int>& candidates, int target,vector<int> &ans,vector<vector<int>> &res,int start){
    //base condition
    if(isSolved(ans,target)){
        res.push_back(ans);
        return;
    }
    //control+BT+choices
    for(int i=start;i<candidates.size();i++){
        //start so always that or next one prev not needed
        if(isValid(ans,target,candidates[i])){
            //only then to do else dont need
            ans.push_back(candidates[i]);
            solve(candidates,target,ans,res,i);
            //backtrack
            ans.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;//to store the ans
        solve(candidates,target,ans,res,0);
        //always keep the track in BT so shd be use of tstart
        return res;
    }
};