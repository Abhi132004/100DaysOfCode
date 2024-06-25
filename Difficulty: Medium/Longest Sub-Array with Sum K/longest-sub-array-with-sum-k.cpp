//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
   int lenOfLongSubarr(int arr[], int N, int k) {
    std::unordered_map<long long, int> cum_sum_map;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++) {
        // Add the current element to the cumulative sum
        sum += arr[i];

        // If the cumulative sum equals the desired sum, update maxLen
        if (sum == k) {
            maxLen = i + 1;
        }

        // If (sum - k) exists in the map, update maxLen
        if (cum_sum_map.find(sum - k) != cum_sum_map.end()) {
            maxLen = std::max(maxLen, i - cum_sum_map[sum - k]);
        }

        // If the cumulative sum is not in the map, add it
        if (cum_sum_map.find(sum) == cum_sum_map.end()) {
            cum_sum_map[sum] = i;
        }
    }

    return maxLen;
}


};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends