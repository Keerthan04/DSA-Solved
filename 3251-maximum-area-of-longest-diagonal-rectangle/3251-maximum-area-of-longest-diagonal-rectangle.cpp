class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        double diagonal = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            double length = dimensions[i][0];
            double width = dimensions[i][1];
            double diagonal_length = sqrt(length * length + width * width);

            if (diagonal_length > diagonal) {
                diagonal = diagonal_length;
                area = (int)length * (int)width;//since area is int we do this
            } else if (diagonal_length == diagonal) {
                area = max(area, (int)length * (int)width);
            }
        }
        return area;
    }
};
