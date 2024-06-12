//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
    for(int i = 1; i <= n; i++){
        std::string a = std::to_string(i);
        for(int j = 0; j < a.size(); j++){
            if(a[j] == '4'){
                count++;
                break; // break as soon as we find a '4' in the number
            }
        }
    }
    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends