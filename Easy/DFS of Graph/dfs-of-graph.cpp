//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Helper function to perform DFS traversal
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& vec) {
        vis[node] = 1;
        vec.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, vec);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> vec;
        // Start DFS from the 0th vertex
        dfs(0, adj, vis, vec);
        return vec;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends