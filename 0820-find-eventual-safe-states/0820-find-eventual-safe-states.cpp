class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V); // Initialize adjRev with size V
        vector<int> indegree(V, 0);
        //reverse the graph and backtrack using the terminal paths
        for(int i =0;i<V;i++){
            //i -> it shd be changed to it->i
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;//so now indegree of i will be increased
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        //normal toposort but with adjRev(reversed graph)
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};