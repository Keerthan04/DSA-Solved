class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l=0,r=0;//l tells buy and r tells sell
        while(r<prices.size()){
            if(prices[r]<prices[l]){
                l=r;//it is good time to buy so
            }
            else{
                maxProfit=max(maxProfit,prices[r]-prices[l]);
            }
            r++;
        }
        return maxProfit;
    }
};