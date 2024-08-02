class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;
            cnt += 1 + *min_element(lastSeen, lastSeen + 3);
        }
        return cnt;
    }
};
