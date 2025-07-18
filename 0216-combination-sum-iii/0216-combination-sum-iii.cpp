class Solution {
public:
    void solve(vector<int>& arr, int k, int n, vector<vector<int>>& res, vector<int>& ans, int start) {
        if (n == 0 && ans.size() == k) {
            res.push_back(ans);
            return;
        }

        if (start >= arr.size()) return;

        if (arr[start] <= n && ans.size() < k) {
            ans.push_back(arr[start]);
            solve(arr, k, n - arr[start], res, ans, start + 1);
            ans.pop_back();
        }

        solve(arr, k, n, res, ans, start + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> ans;
        solve(arr, k, n, res, ans, 0);
        return res;
    }
};
