bool isSolved(vector<int> &ans, int target) {
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum == target;
}

bool isValid(vector<int> &ans, int target, int k) {
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return (sum + k) <= target;
}

void solve(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res, int start) {
    if (isSolved(ans, target)) {
        res.push_back(ans);
        return;
    }
    
    if (start >= candidates.size()) return;

    if (isValid(ans, target, candidates[start])) {
        ans.push_back(candidates[start]);
        solve(candidates, target, ans, res, start); // pick same element
        ans.pop_back();
    }

    solve(candidates, target, ans, res, start + 1); // skip current
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(candidates, target, ans, res, 0);
        return res;
    }
};
