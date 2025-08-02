class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // Max-heap: frequency descending
        priority_queue<pair<int, char>> maxh;
        for (auto& it : freq) {
            maxh.push({it.second, it.first});
        }

        string result;
        while (!maxh.empty()) {
            auto [count, ch] = maxh.top(); maxh.pop();
            result += string(count, ch);  // repeat 'ch' count times
        }

        return result;
    }
};
