class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxRepeatingChar = 0;
        int maxLen = 0;
        unordered_map<char,int> freq;
        int wstart = 0;
        for(int wend = 0;wend<s.length();wend++){
            //so here we need to perform on the back of it ka
            //in this case it is to add freq and find max one
            freq[s[wend]]++;
            //this is to tell us the which is the max repeat char so that keep that and we will replace the other ones
            maxRepeatingChar = max(maxRepeatingChar,freq[s[wend]]);
            //now is the constraint to reduce the window
            if(wend-wstart+1 - maxRepeatingChar > k){
                //so if the window length - most repeated char length > k then we cant replace with k swaps so shrink the window from start
                freq[s[wstart]]--;
                wstart++;
            }
            //so now we have proper thing so maxlen calculate
            maxLen = max(maxLen,wend-wstart+1);
        }
        return maxLen;
    }
};