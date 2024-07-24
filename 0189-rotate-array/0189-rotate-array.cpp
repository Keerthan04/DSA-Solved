class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int i=0;i<n;i++){
            mp[((i+k)%n)] = nums[i];
        }
        for(auto &it:mp){
            nums[it.first]=it.second;
        }
    }
};