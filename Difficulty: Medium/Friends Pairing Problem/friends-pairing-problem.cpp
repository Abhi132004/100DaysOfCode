//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int MOD = 1000000007;
    int countFriendsPairings(int n) 
    { 
        if(n<=2) return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]%MOD+(dp[i-2]*1ll*(i-1))%MOD)%MOD;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends