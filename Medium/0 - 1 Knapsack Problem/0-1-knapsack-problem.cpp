//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Initialize the 2D vector with dimensions (n+1) x (W+1)
    vector<vector<int>> knap(n + 1, vector<int>(W + 1, 0));
    
    // Iterate through all items
    for (int i = 1; i <= n; i++) {
        // Iterate through all capacities from 0 to W
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                // If the item can be included, choose the maximum value
                knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - wt[i - 1]] + val[i - 1]);
            } else {
                // If the item cannot be included, inherit the value from above
                knap[i][j] = knap[i - 1][j];
            }
        }
    }
    
    // Return the maximum value for the full capacity W
    return knap[n][W];
}
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends