//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int f(int n, int m, string s , string t,vector<vector<int>> &dp){
      if(n<0){
          return m+1;
      }
      if(m<0){
          return n+1;
      }
      if(dp[m][n] != -1){
          return dp[m][n];
      }
      if(s[n] == t[m]){
          return f(n-1,m-1,s,t,dp);
      }
      return dp[m][n] = 1+ min(f(n-1,m,s,t,dp),min(f(n,m-1,s,t,dp),f(n-1,m-1,s,t,dp)));
  }
    int editDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(n-1,m-1,s,t,dp);
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends