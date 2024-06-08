//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
 bool isVowel(char x) {
    return x == 'a' || x == 'e' || x == 'i' || x == 'o'
        || x == 'u' || x == 'A' || x == 'E' || x == 'I'
        || x == 'O' || x == 'U';
}



void fn(string S, set<string> &st, string ot = "", int index = 0) {
    if(index == S.length()) {
        if(!ot.empty() && isVowel(ot[0]) && !isVowel(ot[ot.size() - 1])) {
            st.insert(ot);
        }
        return;
    }
      
      fn(S , st , ot+S[index] , index+1);
      fn(S , st , ot , index+1);
  }
  
    set<string> allPossibleSubsequences(string S) {
        // code here
        
        set<string> st;
        fn(S,st);
        return st;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends