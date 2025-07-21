class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board, string& word, int index, int n, int m) {
        if(index == word.size()) return true;
        
        // Store and mark visited
        char temp = board[row][col];
        board[row][col] = '#'; // visited

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 4-directional movement

        for(int k = 0; k < 4; k++) {
            int nrow = row + dirs[k][0];
            int ncol = col + dirs[k][1];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[index]) {
                if(solve(nrow, ncol, board, word, index + 1, n, m)) {
                    return true;
                }
            }
        }

        board[row][col] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i, j, board, word, 1, n, m)) return true;
                }
            }
        }

        return false;
    }
};
