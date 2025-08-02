class Solution {
public:
    double calcDistance(const vector<int>& point) {
        return sqrt(point[0]*point[0] + point[1]*point[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap with <distance, point>
        priority_queue<pair<double, vector<int>>> maxh;
        vector<vector<int>> result;

        for (int i = 0; i < k; i++) {
            maxh.push({calcDistance(points[i]), points[i]});
        }

        for (int i = k; i < points.size(); i++) {
            double dist = calcDistance(points[i]);
            if (dist < maxh.top().first) {
                maxh.pop();
                maxh.push({dist, points[i]});
            }
        }

        while (!maxh.empty()) {
            result.push_back(maxh.top().second);
            maxh.pop();
        }

        return result;
    }
};
