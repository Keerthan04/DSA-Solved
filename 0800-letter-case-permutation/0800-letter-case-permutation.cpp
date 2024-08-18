class Solution {
public:
    void solve(string s,int index,vector<string>&ans,string output){
        if(index==s.size()){
            ans.push_back(output);
            return;
        }

        //including the letters
        //instead can do the direct isalpha(ip)
        if((s[index]>='a' && s[index]<='z') || (s[index]>='A' && s[index]<='Z')){
            //converting to lower and including it
            char lower=tolower(s[index]);
            solve(s,index+1,ans,output+lower);

            //converting to upper and including it
            char upper=toupper(s[index]);
            solve(s,index+1,ans,output+upper);
        }
        
        //including the digits
        else
            solve(s,index+1,ans,output+s[index]);

        
    }

    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(s,0,ans,"");
        return ans;
    }
};