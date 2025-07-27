class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //at first glance it looks like longest substr with k distinct digits where k=2
        int k = 2;
        //but here no constrain that shd be of k so then we update everytime
        unordered_map<int,int> freq;
        int maxLen = 0;
        int wstart = 0;
        for(int wend = 0;wend<fruits.size();wend++){
            //the right part ko add
            freq[fruits[wend]]++;
            //constraint > then removal part
            while(freq.size() > 2){
                freq[fruits[wstart]]--;
                if(freq[fruits[wstart]] == 0) freq.erase(fruits[wstart]);
                wstart++;
            }
            //then check and add
            maxLen = max(maxLen,wend-wstart+1);
            
        }
        return maxLen;
    }
};