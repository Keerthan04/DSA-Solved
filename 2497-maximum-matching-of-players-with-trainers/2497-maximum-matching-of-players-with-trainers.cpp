class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();int m= trainers.size();
        int l=0,r=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(l<m && r<n){
            if(players[r]<=trainers[l]){
                r=r+1;
            }
            l=l+1;
        }
        return r;
    }
};