//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool commonSubseq (string a, string b)
	{
	    // your code here
	    bool check[26];
	    memset(check,false,sizeof(check));
	    for(int i = 0;i<a.length();i++){
	        check[a[i] - 'A'] =true; 
	    }
	    for(int i = 0;i<b.length();i++){
	        if(check[b[i] - 'A']){
	            return true;
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends