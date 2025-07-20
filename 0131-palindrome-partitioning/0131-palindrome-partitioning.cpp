class Solution {
public:
    bool ispali(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(int index,string s,vector<vector<string>> &ans,vector<string> &path){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispali(s,index,i)){
                //check if 0..1 and all are pali i.e left part is pali
                path.push_back(s.substr(index, i - index + 1));//if yes then put that substring
                solve(i+1,s,ans,path);
                path.pop_back();//pop back and backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,ans,path);
        return ans;
    }
};