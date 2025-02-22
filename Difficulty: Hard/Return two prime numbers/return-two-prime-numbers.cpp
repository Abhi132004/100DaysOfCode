//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:


vector<int> primeDivision(int n) {
        vector<bool>sieve(n,true);
        sieve[0] = false;
        sieve[1] = false;
        for(int i=2;i*i<n;i++) {
            if(sieve[i]) {
                for(int j=i*i;j<n;j+=i) {
                    sieve[j] = false;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(sieve[i] && sieve[n-i]) return {i,n-i};
        }
        return {};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends