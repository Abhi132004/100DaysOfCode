//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void fn(int idx , string&S , vector<string> &ans){
	    if(idx == S.size()-1){
	        ans.push_back(S);
	        return;
	    }
	    for(int i = idx;i<S.size();i++){
	        swap(S[i],S[idx]);
	        fn(idx+1,S,ans);
	        swap(S[i],S[idx]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    fn(0,S,ans);
		    sort(ans.begin(),ans.end());
		    ans.erase(unique(ans.begin(),ans.end()),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends