class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matched = 0;
        unordered_map<char,int> freq;
        for(auto character : s1){
            freq[character]++;
        }
        int wstart = 0;
        for(int wend =0; wend<s2.length();wend++){
            char rightChar = s2[wend];
            if(freq.find(rightChar)!=freq.end()){
                //if right char is in the freq then
                freq[rightChar]--;//decrement first and check if 0 -> matched++
                if(freq[rightChar]==0) matched++;
            }
            //if matched at any time becomes = no of characters then true
            if(matched == (int)freq.size()) return true;
            if(wend>=s1.length()-1){
                //if the window size > pattern then from then on we shrink and each iteration maintain the same window(since index 0 in wend we do length -1 and >= else can do >and length only)
                if(freq.find(s2[wstart])!=freq.end()){
                    //the shrinking char is in the window then see if freq =0 then matched-- we do then increase the freq
                    if(freq[s2[wstart]]==0) matched--;
                    freq[s2[wstart]]++;
                }
                wstart++;
            }
        }
        return false;
    }
};