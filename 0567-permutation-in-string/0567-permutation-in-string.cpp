class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length = s1.length();
        if (length > s2.length()) return false;

        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }

        int left = 0, right = 0, count = mp.size();

        while (right < s2.length()) {
            // Reduce count if character in window matches character in s1
            if (mp.find(s2[right]) != mp.end()) {
                mp[s2[right]]--;
                if (mp[s2[right]] == 0) {
                    count--;
                }
            }
            right++;

            // When the window size matches the length of s1
            while (right - left == length) {
                if (count == 0) {
                    return true;
                }

                // Slide the window by removing the leftmost character
                if (mp.find(s2[left]) != mp.end()) {
                    if (mp[s2[left]] == 0) {
                        count++;
                    }
                    mp[s2[left]]++;
                }
                left++;
            }
        }
        return false;
    }
};
