//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n) {
    // Initialize the map to store elements and their frequencies
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int count = 0;
    int reset = 1;
    int start = -1; // Initialize start to -1 to handle the first element correctly
    int j = 0;

    for (auto i = mp.begin(); i != mp.end(); i++) {
        if (j == 0) {
            start = i->first; // Initialize start with the first element
            reset = 1;
             count = 1;// Start the sequence count
            j++;
            continue;
        }
        
        if (i->first - start == 1) {
            start = i->first;
            reset++;
        } else {
            start = i->first; // Reset start to the current element
            reset = 1;        // Reset sequence count to 1
        }
        
        count = max(count, reset);
        j++;
    }

    return count;
}
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends