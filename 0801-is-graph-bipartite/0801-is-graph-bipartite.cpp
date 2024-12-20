class Solution {
private:
    bool bfs(int src,vector<int> &color,vector<vector<int>>& graph){
        color[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //check accross its neighbours
            for(auto adjNode: graph[node]){
                //if not coloured then put opposite colors to it and push to queue
                if(color[adjNode]==-1){
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                }
                //if same color as of node then not bipartite
                else if(color[adjNode]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        //need to go through all components if multiple components are there so
        for(int i =0;i<V;i++){
            if(color[i] == -1){
                if(bfs(i,color,graph)==false) return false;
            }
        }
        return true;
    }
};