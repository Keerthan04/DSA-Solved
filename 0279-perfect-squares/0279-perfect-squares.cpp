class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return 0;      // got answer so no need anything so 0
        if (index == 0) return 1e9;     // if index is 0 whatever is target 0 is not perfect square so we dont need it 

        if (dp[index][target] != -1) return dp[index][target];

        // not take
        int notTake = solve(index - 1, target, dp);

        // take (if possible)
        int take = 1e9;
        int square = index * index;
        if (square <= target) {
            take = 1 + solve(index, target - square, dp); // allow reuse, so pass index
        }

        return dp[index][target] = min(take, notTake);
    }

    int numSquares(int n) {
        int maxSquareRoot = sqrt(n);//perfect square is till sqrt(n) < number so we do this
        vector<vector<int>> dp(maxSquareRoot + 1, vector<int>(n + 1, -1));
        return solve(maxSquareRoot, n, dp);
    }
};
