class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false; // check before st.top()

                switch (c) {
                    case ')':
                        if (st.top() != '(') return false;
                        st.pop();
                        break;
                    case ']':
                        if (st.top() != '[') return false;
                        st.pop();
                        break;
                    case '}':
                        if (st.top() != '{') return false;
                        st.pop();
                        break;
                    default:
                        return false; // invalid character
                }
            }
        }
        return st.empty(); // return true only if all are matched
    }
};
