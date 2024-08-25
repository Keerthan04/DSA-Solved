int solve(int i,int j, vector<vector<int>> &dp,vector<vector<int>>& triangle){
    //base condition is
    if(i==triangle.size()-1) return triangle[i][j];//reached the last row
    //dp check
    if(dp[i][j]!= -1) return dp[i][j];
    //do all stuffs
    int down = triangle[i][j] + solve(i+1,j,dp,triangle);
    int diagonal = triangle[i][j]+ solve(i+1,j+1,dp,triangle);
    return dp[i][j] = min(down,diagonal);
}
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int m = triangle.size();
        vector<vector<int>> dp(m);
        //sice triangle we need to do like this as not the constant column so ig
        for(int i = 0; i < m; ++i) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }
        //for tabulation the base cond part
        for(int j=0;j<triangle[m-1].size();j++){
            dp[m-1][j] = triangle[m-1][j];
        }
        //so express in for loops always the opp in for loop(IMP) so here n to 0 move
        for(int i = m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j]+ dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];//as we start in memo from 0,0 here also shd be same
    }
};