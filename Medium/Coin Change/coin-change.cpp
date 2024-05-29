//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
    long long int a[N + 1][sum + 1]; // Increase array size by 1
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                a[i][0] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i - 1] <= j) {
                a[i][j] = a[i - 1][j] + a[i][j - coins[i - 1]];
            } else {
                a[i][j] = a[i - 1][j];
            }
        }
    }

    return a[N][sum];
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends