//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // char arr[str.size()];
        string s = "";
        // for(int i = str.size()-1;i>=0;i--){
        //     arr[i] = str[i];
        // }
        for(int i = str.size()-1;i>=0;i--){
            s.push_back(str[i]);
        }
        return s;
        
        // Your code goes here
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends