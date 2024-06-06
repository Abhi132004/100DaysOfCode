//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        for(int i = 0;i<S.size();i++){
            if(S[i] =='.'){
                S[i] = ' ';
            }
        }
       vector<string> words;
       string temp ="";
       stringstream ss(S);
       
       while(ss>>temp){
           words.push_back(temp);
       }
       
       temp = "";
       
       for(int i = words.size()-1;i>=0;i--){
           temp.append(words[i]);
           temp.push_back('.');
           if(i==0){
               temp.pop_back();
           }
       }
       return temp;
       
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends