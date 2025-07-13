class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Remove remaining from end
        while (k-- > 0 && !st.empty()) {
            st.pop();
        }

        // Build result string efficiently
        string res;
        res.reserve(st.size());
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};
