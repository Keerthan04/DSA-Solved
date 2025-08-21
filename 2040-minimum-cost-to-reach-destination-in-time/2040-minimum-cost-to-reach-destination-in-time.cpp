class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // dp[node][time] = min cost to reach
        vector<vector<int>> dp(n, vector<int>(maxTime+1, INT_MAX));
        dp[0][0] = passingFees[0];

        using T = pair<int, pair<int,int>>; // {cost, {node, time}}
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({passingFees[0], {0,0}});

        while(!pq.empty()) {
            auto [cost, p] = pq.top();
            pq.pop();
            int node = p.first;
            int t = p.second;
            if (node == n-1) return cost;

            for (auto &edge : adj[node]) {
                int nxt = edge.first, w = edge.second;
                if (t + w <= maxTime) {
                    int newCost = cost + passingFees[nxt];
                    if (newCost < dp[nxt][t+w]) {
                        dp[nxt][t+w] = newCost;
                        pq.push({newCost, {nxt, t+w}});
                    }
                }
            }
        }
        return -1;
    }
};
