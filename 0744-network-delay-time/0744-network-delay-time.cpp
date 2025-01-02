class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,1e9);
        for( auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>> q;
        q.push({0,k});
        dist[k] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int node = it.second;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    q.push({dis+edW,adjNode});
                }
            }
        }
        int time =0;
        for(int i =1 ; i<=n;i++){
            if(dist[i] == 1e9) return -1;
            time = max(time,dist[i]);
        }
        return time;
    }
};