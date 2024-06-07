//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram


int remAnagram(string str1, string str2)
{
// Your code goes here

    unordered_map<char,int> mp;
   
   for(char i : str1){
       mp[i]++;
   }
   
   for(char i:str2){
       mp[i]--;
   }
   
   int count = 0;
   for(auto par : mp){
       count+=abs(par.second);
   }
   
   return count;
    
   
    
    

}






