class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0);vector<int>cur(2,0);//only two to store the ahead and curr
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    cur[j] = max(-prices[i]+ahead[0],ahead[1]);
                }else{
                    cur[j] = max(prices[i]+ahead[1],ahead[0]);
                }
                ahead = cur;
            }
        }
        return cur[1];//as ind=0 and buy=1 is start
    }
};