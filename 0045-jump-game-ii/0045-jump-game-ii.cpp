class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps =0;
        int l=0,r=0;
        while(r<n-1){//to stop when we reach the last or go beyond it
            int farthest =0;
            for(int i=l;i<=r;i++){
                //for the entire prev range find the next farthest so this
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};