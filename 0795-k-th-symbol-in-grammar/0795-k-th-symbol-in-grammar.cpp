class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1 || n==1) return 0;
        int newK;
        if(k%2==1){
            newK =k/2+1;
        }
        else{
            newK = k/2;
        }
        int res = kthGrammar(n-1,newK);
        if((k%2==1 && res == 0) || (k%2==0 && res ==1)) return 0;
        else if((k%2==1 && res == 1) || (k%2==0 && res ==0)) return 1;
        return 1;
    }
};