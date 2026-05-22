class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int nei = 1; nei < adj.size(); nei++) {
            if (adj[node][nei] == 0) continue;
            if (visited[nei] && nei != parent)
                return true;
            if (!visited[nei]) {
                if (dfs(nei, node, adj, visited))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
      
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            vector<bool> visited(n + 1, false);
            if (dfs(u, -1, adj, visited)) {
                return {u, v};
            }
        }
        return {};
    }
};

