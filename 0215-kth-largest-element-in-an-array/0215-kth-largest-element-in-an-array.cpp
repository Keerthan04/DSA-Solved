class Solution {
public:
    //since basic k and largest given we can use the heap and solve
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int i = 0; i < nums.size(); i++) {
            minh.push(nums[i]);
            if (minh.size() > k) {
                minh.pop();
            }
        }
        return minh.top();
    }
};
