class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0); // Renamed to degree for clarity
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= n; i++){
            // FIX 1: Undirected leaf nodes have a degree of 1, never 0
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int u = q.front();
            topo.push_back(u);
            q.pop();
            for(auto it : adj[u]){
                degree[it]--;
                // FIX 1 (cont.): Check for degree == 1 to find the next leaf node
                if(degree[it] == 1){
                    q.push(it);
                }
            }
        }
        
        // FIX 3: Loop backwards from (n-1) to 0 to find the LAST redundant edge
        for(int i = n - 1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            // FIX 2: Cycle nodes will maintain a degree > 1 after peeling
            if(degree[u] > 1 && degree[v] > 1){
                return {u, v};
            }
        }
        
        return {};
    }
};
