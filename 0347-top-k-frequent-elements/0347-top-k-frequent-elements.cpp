class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Min-heap to store {frequency, number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minh;

        for (auto& it : freq) {
            minh.push({it.second, it.first});//push as freq,ele
            if (minh.size() > k) {
                minh.pop();
            }
        }

        vector<int> res;
        while (!minh.empty()) {
            res.push_back(minh.top().second);
            minh.pop();
        }

        return res;
    }
};
