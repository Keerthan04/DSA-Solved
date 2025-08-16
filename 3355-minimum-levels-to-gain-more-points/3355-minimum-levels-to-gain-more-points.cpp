class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        unordered_map<int,int> freq;
        for(int i = 0;i<possible.size();i++) freq[possible[i]]++;
        int alice =0;int minlevels=INT_MAX;int level =0;
        for(int i =0;i<possible.size()-1;i++){
            int val = possible[i];
            level++;
            if(val==1){
                alice +=1;
            }else{
                alice -=1;
            }
            freq[val]--;
            int bob = (freq[1]*1) + (freq[0]*(-1));
            if(alice > bob) minlevels = min(level,minlevels);
        }
        if(minlevels == INT_MAX) return -1;
        else return minlevels;
    }
};