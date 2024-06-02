//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	
	
	
	
	int findMaxSum(int *a, int n) {
	    // code here
	    
	    vector<int> dp(n,0);
	   // int pick = 0;
	   
	   int prev = a[0];
	   int prev2 = 0;
	    for(int i = 1;i<n;i++){
	        
            int pick = a[i];
	        if(i>1){
	            pick += prev2;
	        }

	        int notPick = 0+ prev;
	        int curri = max(pick,notPick);
	        prev2 = prev;
	        prev = curri;
	    }
	    return prev;;
	    
	}
	
	
	
// 	memoization
// 	int f(int *arr,int n,vector<int> &dp){
// 	    if(n==0){
// 	        return arr[n];
// 	    }
// 	    if(n<0){
// 	        return 0;
// 	    }
// 	    if(dp[n]!=-1){
// 	        return dp[n];
// 	    }
// 	    int pick = arr[n] + f(arr,n-2,dp);
// 	    int notPick = 0 + f(arr,n-1,dp);
// 	    return dp[n] = max(pick,notPick);
// 	}
// 	int findMaxSum(int *arr, int n) {
// 	    // code here
	    
// 	    vector<int> dp(n,-1);
// 	    return f(arr,n-1,dp);
	    
	    
// 	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends