//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
          int n = arr.size();
        map<char,queue<int>>x;
        vector<bool>visited(26,false);
        string ans = arr[0];
        for(int i=1; i<n; i++){
            string str = arr[i];
            x[str[0]].push(i);
        }

        for(int i=1; i<n; i++){
            int len = ans.length()-1;
            if(x.find(ans[len]) != x.end()){
                visited[ans[len] - 'a'] = true;
                int ind = x[ans[len]].front();
                x[ans[len]].pop();
                ans+=arr[ind];
                
                if(x[ans[len]].empty() == true) {
                    x.erase(ans[len]);
                }
            }
            else{
                if(ans[0] == ans[len]){
                    bool flag = false;
                    for(int j=0; j<26; j++){
                        if(visited[j] == true && x.find('a' + j) != x.end()){
                              flag = true;
                              int ind = x['a' + j].front();
                              x['a' + j].pop();
                               ans = arr[ind];
                              if(x['a' + j].empty() == true) x.erase('a' + j); 
                              break;
                        }
                    }
                    if(flag == false) return false;
                }
                else{
                    return 0;
                }
            }
        }
        int len = ans.length()-1;
        if(ans[0] == ans[len]) return true;
        else return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends