//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  int mod=1003;
    int t[205][205][2];
    int solve(string s,int i,int j, bool isTrue){
        int ans=0;
        if(i>j)return 0;
        if(i==j){
            if(isTrue)return (s[i]=='T');
            else{
                return (s[i]=='F');
            }
        }
        if(t[i][j][isTrue]!=-1)return t[i][j][isTrue];
        for(int k=i+1;k<=j-1;k=k+2){
            int lt,lf,rt,rf;
            if(t[i][k-1][1]!=-1){
                lt=t[i][k-1][1];
            }
            else{
                lt=solve(s,i,k-1,1);
                t[i][k-1][1]=lt;
            }
            if(t[i][k-1][0]!=-1){
                lf=t[i][k-1][0];
            }
            else{
                lf=solve(s,i,k-1,0);
                t[i][k-1][0]=lf;
            }
            if(t[k+1][j][1]!=-1){
                rt=t[k+1][j][1];
            }
            else{
                rt=solve(s,k+1,j,1);
                t[k+1][j][1]=rt;
            }
            if(t[k+1][j][0]!=-1){
                rf=t[k+1][j][0];
            }
            else{
                rf=solve(s,k+1,j,0);
                t[k+1][j][0]=rf;
            }
            if(s[k]=='&'){
                if(isTrue){
                    ans=(ans+lt*rt)%mod;
                }
                else{
                    ans=(ans+lf*rt+rf*lt+lf*rf)%mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ans=(ans+lt*rt+lt*rf+lf*rt)%mod;
                }
                else{
                    ans=(ans+lf*rf)%mod;
                }
            }
            else if(s[k]=='^'){
                if(isTrue){
                    ans=(ans+lf*rt+lt*rf)%mod;
                }
                else{
                    ans=(ans+lt*rt+lf*rf)%mod;
                }
            }
        }
        t[i][j][isTrue]=ans;
        return ans;
    }
    int countWays(int n, string s){
        // code here
        int i=0;
        int j=n-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j,true);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends