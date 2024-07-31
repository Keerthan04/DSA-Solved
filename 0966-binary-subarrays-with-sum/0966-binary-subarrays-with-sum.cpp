class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        int prefix=0;int cnt=0;
        map[0]=1;//initialize 0 to 1
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int rem = prefix-goal;//find reminder to check if it is in map
            cnt+=map[rem];//count of the prefix ka we shd add
            map[prefix]+=1;//add all
        }
        return cnt;
    }
};