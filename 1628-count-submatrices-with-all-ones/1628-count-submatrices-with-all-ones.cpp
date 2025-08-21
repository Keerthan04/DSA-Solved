class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> width(m, vector<int>(n, 0));
        int ans = 0;

        // Step 1: Precompute horizontal widths
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    width[i][j] = (j == 0 ? 1 : width[i][j-1] + 1);
                }
            }
        }

        // Step 2: Count submatrices
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int minWidth = width[i][j];
                    for (int k = i; k >= 0; k--) {
                        if (width[k][j] == 0) break;
                        minWidth = min(minWidth, width[k][j]);
                        ans += minWidth;
                    }
                }
            }
        }

        return ans;
    }
};
