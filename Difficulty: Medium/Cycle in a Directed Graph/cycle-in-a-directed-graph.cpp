//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
         int n = V;
        vector<int> indegree(n,0);
        
        for(int i = 0; i < n; i++){
            for(auto it  : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int item = q.front(); q.pop();
            
            cnt++;
            
            for(auto it : adj[item]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(cnt == n) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends