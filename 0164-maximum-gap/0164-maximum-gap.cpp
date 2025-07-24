class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        if(nums.size()==2) return abs(nums[0]-nums[1]);
        sort(nums.begin(),nums.end());
        int diff =0;
        for(int i = 0; i<=nums.size()-2;i++){
            cout<<"ran"<<endl;
            diff = max(diff,abs(nums[i]-nums[i+1]));
        }
        return diff;
    }
};