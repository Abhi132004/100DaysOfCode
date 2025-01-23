//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int isPatternPresent(string S, string P) {
        
        int sizeP = P.size(),sizeS = S.size();
        
        if(P[0]=='^'){
           for(int i=0;i<sizeP-1;i++){
                if(P[i+1]!=S[i])return 0;
           }
           return 1;
        }
        else if(P[sizeP-1]=='$'){
           for(int i=0;i<sizeP-1;i++){
               if(P[sizeP-i-2]!=S[sizeS-i-1])return 0;
           }
           return 1;
        }
        else {
            int pRun=0;
            for(int i=0;i<sizeS;i++){
                if(pRun==sizeP)return 1;
                P[pRun]==S[i]?++pRun:pRun=0;
            }
            return (pRun==sizeP)?1:0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string P,S;

        cin>>P;
        cin>>S;

        Solution ob;
        cout << ob.isPatternPresent(S,P) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends