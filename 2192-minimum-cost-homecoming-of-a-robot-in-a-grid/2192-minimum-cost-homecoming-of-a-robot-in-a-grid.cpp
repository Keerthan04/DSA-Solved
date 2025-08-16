class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        int cost = 0;

        // Move vertically
        if (r1 < r2) {
            for (int i = r1 + 1; i <= r2; i++) cost += rowCosts[i];
        } else {
            for (int i = r1 - 1; i >= r2; i--) cost += rowCosts[i];
        }

        // Move horizontally
        if (c1 < c2) {
            for (int j = c1 + 1; j <= c2; j++) cost += colCosts[j];
        } else {
            for (int j = c1 - 1; j >= c2; j--) cost += colCosts[j];
        }

        return cost;
    }
};
