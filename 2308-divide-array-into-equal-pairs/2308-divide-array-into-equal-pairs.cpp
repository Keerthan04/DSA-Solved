class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return false;
        }
        //for divide each number shd be even no of times if not then false
        return true;
    }
};
