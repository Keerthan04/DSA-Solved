class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int top=0 ,bot = rows-1;
        while(top<=bot){
            int mid = (top+bot)/2;
            if(target > matrix[mid][cols-1]) top=mid+1;
            else if(target < matrix[mid][0]) bot = mid-1;
            else{
                //same row 
                break;
            }
        }
        //if loop ended meaning no 
        if(!(top<=bot)) return false;
        int row = (top + bot)/2;//getting the row
        int l  = 0 ,r= cols-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target > matrix[row][m]) l =m+1;
            else if(target< matrix[row][m]) r = m -1;
            else{
                //got ele so
                return true;
            }
        }
        return false;
    }
};
