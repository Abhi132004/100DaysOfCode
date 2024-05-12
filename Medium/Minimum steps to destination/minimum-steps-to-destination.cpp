//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
    int count = 0;
    int check = 0;
    for (int i = 1; ; i++) {
        if ((check + i) >= d && (check + i - d) % 2 == 0) {
            return i;
        }
        check += i;
    }
}

};
//Back-end complete function Template for C++



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends