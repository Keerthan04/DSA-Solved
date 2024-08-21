bool isSolved(const vector<int>& ans, int target) {
    int sum = accumulate(ans.begin(), ans.end(), 0);  // Initialize sum to 0
    return sum == target;
}

bool isValid(const vector<int>& ans, int target, int k) {
    int sum = accumulate(ans.begin(), ans.end(), 0);  // Initialize sum to 0
    return (sum + k) <= target;  // Ensure the sum does not exceed the target
}

// Define a custom comparator for vector<int> to use with set
struct VectorComparator {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    }
};

void solve(vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res, int start, set<vector<int>, VectorComparator>& st) {
    // Base condition
    if (isSolved(ans, target)) {
        vector<int> sorted_ans = ans;
        sort(sorted_ans.begin(), sorted_ans.end());
        if (st.find(sorted_ans) == st.end()) {
            st.insert(sorted_ans);
            res.push_back(ans);
        }
        return;
    }
    
    // Control + BT + Choices
    for (int i = start; i < candidates.size(); i++) {
        // Skip duplicate elements to avoid duplicate combinations
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        if (isValid(ans, target, candidates[i])) {
            ans.push_back(candidates[i]);
            solve(candidates, target, ans, res, i + 1, st);  // Move to the next index to avoid reusing the same element
            ans.pop_back();  // Backtrack
        }
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;  // To store the answer
        set<vector<int>, VectorComparator> st;
        sort(candidates.begin(), candidates.end());  // Sort candidates to handle duplicates
        solve(candidates, target, ans, res, 0, st);
        return res;
    }
};