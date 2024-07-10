class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int num = numbers[l]+numbers[r];
            if(num>target) r--;
            else if(num<target) l++;
            else{
                return {l+1,r+1};
            }
        }
        return {-1,-1};
    }
};