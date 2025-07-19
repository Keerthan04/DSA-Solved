class Solution {
public:
    void solve(vector<vector<int>>& answers, vector<int> nums, vector<int> indianswers,int index) {
        if (index == nums.size()) {
            answers.push_back(indianswers);
            return;
        }
        //choose the ele in index
        indianswers.push_back(nums[index]);
        solve(answers,nums,indianswers,index+1);//then call from next
        //now dont pick so remove the added ele in indianswers
        indianswers.pop_back();
        solve(answers,nums,indianswers,index+1);//again run fo next elements
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;
        vector<int> indianswers;
        solve(answers, nums, indianswers,0);
        return answers;
    }
};
