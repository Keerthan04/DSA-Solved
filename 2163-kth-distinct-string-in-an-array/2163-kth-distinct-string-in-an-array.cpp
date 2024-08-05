class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        for(auto i : arr){
            mpp[i]++;
        }
        //all the count we do then
        for(auto i : arr){
            if(mpp[i]==1){
                //meaning distict so decrement k and then if k ==0 then that is kth distict so
                //return that
                k--;
                if(k==0){
                    return i;
                }
            }
        }
        return "";
    }
};