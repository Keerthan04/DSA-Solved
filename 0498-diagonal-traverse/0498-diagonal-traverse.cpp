class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n = mat[0].size();
        vector<int> ans;
        if(n==0 || m==0){
            return ans;
        }
        int row=0,col=0;
        for(int i=0;i<m*n;i++){
            ans.push_back(mat[row][col]);
            if((row+col)%2==0){
               if(col==n-1){
                    row++;
                }
                 else if(row==0){
                    col++;
                }
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row==m-1){
                    col++;
                }
                else if(col==0){
                    row++;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};