class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int matched =0;
        int wstart=0;
        vector<int> ans;
        unordered_map<char,int> freq;
        for(auto character:p){
            freq[character]++;
        }
        for(int wend = 0;wend<s.length();wend++){
            if(freq.find(s[wend])!=freq.end()){
                freq[s[wend]]--;
                if(freq[s[wend]]==0) matched++;
            }
            if(matched == freq.size()) {
                ans.push_back(wend-(p.length()-1));
            }
            if(wend >=p.length()-1){
                if(freq.find(s[wstart])!=freq.end()){
                    if(freq[s[wstart]]==0) matched--;
                    freq[s[wstart]]++;
                }
                wstart++;
            }
        }
        return ans;
    }
};