class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int wstart = 0;
        unordered_map<char,int> indexMap;
        for(int wend = 0;wend<s.size();wend++){
            int rightChar = s[wend];
            if(indexMap.find(rightChar)!=indexMap.end()){
                //means already present in the indexMap
                //so remove till that char
                wstart = max(wstart,indexMap[rightChar]+1);
            }
            indexMap[rightChar] = wend;
            maxLen = max(maxLen,wend-wstart+1);
        }
        return maxLen;
    }
};