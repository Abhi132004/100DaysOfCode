//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
     int romInt(char s){
      switch(s){
          case 'I':return 1;
          case 'V':return 5;
          case 'X': return 10;
          case 'L': return 50;
          case 'C': return 100;
          case 'D': return 500;
          case 'M': return 1000;
      }
      return 0;
  }
  
  
    int romanToDecimal(string &str) {
     
     int sum = 0;
        int n = str.size();
        for(int i = 0;i<str.size();i++){
            if(i+1<n && romInt(str[i]) < romInt(str[i+1])){
                sum = sum - romInt(str[i]);
            }
            else{
                sum+=romInt(str[i]);
            }
        }
        
        return abs(sum);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends