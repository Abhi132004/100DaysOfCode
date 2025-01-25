//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
int mod=1e9+7;
void solve(vector<vector<long long int>>&a,vector<vector<long long int>>&b){
    long long int p=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
    long long int q=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
	long long int r=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
    long long int s=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;
	a[0][0]=p;
	a[0][1]=q;
	a[1][0]=r;
	a[1][1]=s;
	return ;
}
void power(vector<vector<long long int>>&a,long long int n){
    if (n==1|| n==0)return ;
    if (n%2==0){
        power(a,n/2);
        solve(a,a);
        return;
    }
    power(a,n/2);
    solve(a,a);
    vector<vector<long long int>>curr={{2,5},{1,0}};
    solve(a,curr);
	return;
}
long long int NthTerm(long long int n)
{
    // Code here
    //nth term would be of the form sum of first n-2 elements + previous element
    //after deducing the linear relation the nth term would be as 2*(n-1)th term+5*(n-2)th term
    //using matrix exponentiatio to solve this
    if (n<=2)return 1;
    vector<vector<long long int>>a={{2,5},{1,0}};
    power(a,n-2);
    return (a[0][0]+a[0][1])%mod;
    
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NthTerm(N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends