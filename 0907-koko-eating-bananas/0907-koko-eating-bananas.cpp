class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *max_element(piles.begin(),piles.end());//find the max in piles
        int res = r;
        while(l<=r){
            int k = (l+r)/2;
            long long totalTime =0;
            for(int p: piles){
                //for each mid find the total time for it to be done
                totalTime+= ceil(static_cast<double>(p)/k);
            }
            if(totalTime<=h){
                //if can be done then that can be and others is left of it so 
                res = k;
                r=k-1;
            }
            else{
                //else go right of it
                l=k+1;
            }
        }
        return res;
    }
};
