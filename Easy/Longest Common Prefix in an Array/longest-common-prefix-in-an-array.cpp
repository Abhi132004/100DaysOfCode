//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:

void fn(const string s1, const string &s2, string &temp) {
    temp = "";
    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] == s2[i]) {
            temp.push_back(s1[i]);
        } else {
            break;
        }
    }
}

string longestCommonPrefix(string arr[], int n) {
    if (n == 0) {
        return "-1";
    }
    if (n == 1) {
        return arr[0];
    }
    string temp = arr[0];
    for (int i = 1; i < n; i++) {
        fn(temp, arr[i], temp);
        if (temp == "") {
            return "-1";
        }
    }
    return temp;
}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends