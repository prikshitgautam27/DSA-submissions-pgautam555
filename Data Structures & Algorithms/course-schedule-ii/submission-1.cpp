class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int n= numCourses;
        vector<int>indegree(n,0);
        for(auto e: prerequisites){
            int u=e[0];
            int v=e[1];

            adj[v].push_back(u);
            indegree[u]++;
        }
queue<int>q;
vector<int>topo;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                        q.push(it);
                }
            }

            
        }
        if(n==topo.size()){
            return topo;
        }
        return {};
    }
};
