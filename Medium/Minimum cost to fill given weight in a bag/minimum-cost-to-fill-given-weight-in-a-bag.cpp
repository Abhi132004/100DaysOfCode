//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumCost(int n, int w, std::vector<int>& cost) {
        std::vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;  

  
        for (int i = 1; i <= w; i++) {
       
            for (int j = 1; j <= n; j++) {
               
                if (j <= i && cost[j - 1] != -1) {
           
                    if (dp[i - j] != INT_MAX) {
                        dp[i] = std::min(dp[i], dp[i - j] + cost[j - 1]);
                    }
                }
            }
        }

        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends