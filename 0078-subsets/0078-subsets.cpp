class Solution {
public:
    void solve(vector<vector<int>>& answers, vector<int> nums, vector<int> indianswers) {
        if (nums.size() == 0) {
            answers.push_back(indianswers);
            return;
        }

        // Option 1: Do not include the first element of nums
        vector<int> op1 = indianswers;

        // Option 2: Include the first element of nums
        vector<int> op2 = indianswers;
        op2.push_back(nums[0]);

        // Remove the first element from nums for the recursive calls
        nums.erase(nums.begin());

        // Recurse with the two options
        solve(answers, nums, op1);
        solve(answers, nums, op2);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;
        vector<int> indianswers;
        solve(answers, nums, indianswers);
        return answers;
    }
};
