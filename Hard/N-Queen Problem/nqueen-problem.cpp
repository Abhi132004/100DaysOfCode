//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isSafe(int row,int col, vector<vector<int>> &helper,int n){
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0){
            if(helper[row][col] == 1) return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while( col>=0){
            if(helper[row][col] == 1) return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(helper[row][col] == 1) return false;
            col--;
            row++;
        }
        
        return true;
        
    }
    void solve(int col , vector<int> &board,vector<vector<int>> &ans,int n , vector<vector<int>> helper){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){ //i->row
            if(isSafe(row,col,helper,n)){
                board.push_back(row + 1);
                helper[row][col] = 1;
                solve(col+1,board,ans,n,helper);
                board.pop_back();
                helper[row][col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        
        int m = n;
        vector<vector<int>> ans;
        vector<vector<int>> helper(n,vector<int>(n,0));
        vector<int> board;
        
        solve(0,board,ans,n,helper);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends