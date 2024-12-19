class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,-1));
        //no need the visited as we do using the dis only if -1 then not visited so
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dis[nrow][ncol]==-1){
                    q.push({nrow,ncol});
                    dis[nrow][ncol] = dis[row][col]+1;
                }
            }
        }
        return dis;
    }
};