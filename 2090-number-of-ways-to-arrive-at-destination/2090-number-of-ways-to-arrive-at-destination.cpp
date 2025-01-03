class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7; // Modulo for large numbers
        vector<vector<pair<int, int>>> adj(n);
        
        // Build adjacency list
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Use long long for distances to avoid overflow
        vector<long long> dist(n, 1e18); // Initialize to a very large value
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Start from node 0
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;
            
            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;
                
                // Found a new shorter path
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    ways[adjNode] = ways[node]; // Set ways equal to current node
                    pq.push({dist[adjNode], adjNode});
                } 
                // Found another path with the same shortest distance
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
