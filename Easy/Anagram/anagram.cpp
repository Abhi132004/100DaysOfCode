//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        
         if (a.size() != b.size()) {
        return false;
    }
    
    std::unordered_map<char, int> mp;
    
    // Count characters in string a
    for (char ch : a) {
        mp[ch]++;
    }
    
    // Subtract count using characters in string b
    for (char ch : b) {
        mp[ch]--;
    }
    
    // Check if all counts are zero
    for (auto it : mp) {
        if (it.second != 0) {
            return false;
        }
    }
    
    return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends