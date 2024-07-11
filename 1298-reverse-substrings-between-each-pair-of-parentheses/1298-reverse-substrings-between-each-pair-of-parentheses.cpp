class Solution {
public:
    string reverseParentheses(std::string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                if (!stk.empty()) {
                    stk.pop();
                }
                for (char ch : temp) {
                    stk.push(ch);
                }
            } else {
                stk.push(c);
            }
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};