//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void fn(vector<vector<int>> &m, int n, vector<string>&res,string& temp ,int x=0,int y = 0){
        if(x<0 || y<0 || x>=n || y>=n || m[x][y] == 0){
            return;
        }
        if(x == n-1 && y == n-1){
            res.push_back(temp);
            return;
        }
        
        m[x][y] = 0;
        temp.push_back('D');
        fn(m,n,res,temp,x+1,y);
        temp.pop_back();
        
        temp.push_back('R');
        fn(m,n,res,temp,x,y+1);
        temp.pop_back();
        
        
            temp.push_back('L');
            fn(m,n,res,temp,x,y-1);
            temp.pop_back();

        
            temp.push_back('U');
            fn(m,n,res,temp,x-1,y);
            temp.pop_back();

        m[x][y] = 1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string temp = "";
        fn(m,n,res,temp);
        return res;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends