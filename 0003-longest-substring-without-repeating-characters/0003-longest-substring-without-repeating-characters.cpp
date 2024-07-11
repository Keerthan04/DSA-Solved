class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dup;
        int l=0,r=0,res=0;
        while(r<s.size()){
            if(dup.find(s[r])==dup.end()){
                dup.insert(s[r]);
                res=max(res,r-l+1);
                r++;
            }
            else{
                //ele is in set so dup it is
                while(s[l]!=s[r]){
                    dup.erase(s[l]);
                    l++;
                }
                dup.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};