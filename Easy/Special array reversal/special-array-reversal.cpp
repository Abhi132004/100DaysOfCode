//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    bool isSpecialChar(char c){
        return !isalnum(c) && !isspace(c);
    }
    string reverse(string s)
    { 
       
       int left = 0;
       int right = s.size() - 1;
       
       while(left < right){
           if(!isSpecialChar(s[left]) && !isSpecialChar(s[right])){
               swap(s[left] , s[right]);
               left++;
               right--;
           }
           else if(!isSpecialChar(s[left]) && isSpecialChar(s[right])){
               right--;
           }
           else if(isSpecialChar(s[left]) && !isSpecialChar(s[right])){
               left++;
           }
           else{
               left++;
               right--;
           }
       }
       
       return s; 
        
        
        
        
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends