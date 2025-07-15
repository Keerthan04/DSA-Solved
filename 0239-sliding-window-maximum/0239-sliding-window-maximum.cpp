class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;//n-k windows will be there
        deque<int> dq;//store index
        for(int i=0;i<nums.size();i++){
            //first to see if windown valid if not then from front remove
            if(!dq.empty() && dq.front() <= i-k ){
                dq.pop_front();
            }
            //window valid then monotonic stack decresing order maintain
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                //then pop from back
                dq.pop_back();
            }
            //now we add the index
            dq.push_back(i);
            //now if we have window then answer store and always after i >= k-1 window so store and the answer will be at the front as store in decreasing order
            if(i>=k-1) ans.push_back(nums[dq.front()]);//so once the first window done then store all
        }
        return ans;
    }
};