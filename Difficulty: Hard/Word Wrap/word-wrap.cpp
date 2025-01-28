//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int f(int j, int n, int k, vector<int> &arr, vector<int> &dp)
    {
        if(j==n)
        return 0;
        
        if(dp[j]!=-1)
        return dp[j];
        
        int ans=1e9, till=0;
        
        for(int i=j;i<n;i++)
        {
            till+=arr[i];
            if(k-till-(i-j)<0)
            break;
            
            int temp=f(i+1, n, k, arr, dp);
            if(i!=n-1)
            temp+=(k-till-(i-j))*(k-till-(i-j));
            
            ans=min(ans, temp);
        }
        return dp[j]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        vector<int> dp(n, -1);
        return f(0, n, k, nums, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while (ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends