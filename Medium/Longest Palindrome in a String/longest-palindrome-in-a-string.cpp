//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        string a = s.substr(0,1);
        int maxlength = 1;
        
        for(int diff = 0;diff<n;diff++){
            for(int i = 0,j = i+diff;j<n;i++,j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(diff == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] > 0){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                
                if(dp[i][j]){
                    if((j-i+1) > maxlength){
                        maxlength = j-i+1;
                        a = s.substr(i,j-i+1);
                    }
                }
                
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends