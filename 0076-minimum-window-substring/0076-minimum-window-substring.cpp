class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        vector<int>hash(256,0);

        int l=0,r=0,minlen=INT_MAX,sind=-1,cnt=0;

        int n=s.size(),m=t.size();

        //preinseting
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){
            //if already preinsert then count ++
            if(hash[s[r]]>0){
               cnt++;
            }
            hash[s[r]]--;//then decrease the count
            
            while(cnt==m){
                //if equal then check of min and then till valid min we go shrinking
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sind=l;
                }
                hash[s[l]]++;

                if(hash[s[l]]>0){//on insert if it is greater than 0 means the preinserted thing i added so my substring is not valid so decrease the count now
                    cnt=cnt-1;
                }

                l++;
            }
            r=r+1;
        }
        
        return sind==-1?"":s.substr(sind,minlen);
    
    }
};