class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // adjacency list: source → sorted destinations
        unordered_map<string, multiset<string>> graph;
        for (auto &e : tickets) {
            graph[e[0]].insert(e[1]);
        }

        vector<string> ans;
        dfs("JFK", graph, ans);
        reverse(ans.begin(), ans.end()); // reverse because of post-order
        return ans;
    }

private:
    void dfs(string u, unordered_map<string, multiset<string>> &graph, vector<string> &ans) {
        while (!graph[u].empty()) {
            string v = *graph[u].begin();   // smallest lexical destination
            graph[u].erase(graph[u].begin());
            dfs(v, graph, ans);
        }
        ans.push_back(u);  // add after exploring all edges
    }
};
