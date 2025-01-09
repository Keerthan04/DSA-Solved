class Solution {
public:
    bool check(string pref,string word){
        for(int i =0;i<pref.length();i++){
            if(word[i]!=pref[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i =0;i<words.size();i++){
            if(check(pref,words[i])) count++;
        }
        return count;
    }
};