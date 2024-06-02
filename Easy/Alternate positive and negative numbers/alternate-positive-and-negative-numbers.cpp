//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

void rearrange(int arr[], int n) {
    queue<int> pos;
    queue<int> neg;

    // Step 1: Separate positive and negative numbers into different queues
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) {
            pos.push(arr[i]);
        } else {
            neg.push(arr[i]);
        }
    }

    int index = 0;
    // Step 2: Place alternating positive and negative numbers
    while(!pos.empty() && !neg.empty()) {
        if(index % 2 == 0) {
            arr[index++] = pos.front();
            pos.pop();
        } else {
            arr[index++] = neg.front();
            neg.pop();
        }
    }

    // Step 3: Place remaining positive numbers, if any
    while(!pos.empty()) {
        arr[index++] = pos.front();
        pos.pop();
    }

    // Step 4: Place remaining negative numbers, if any
    while(!neg.empty()) {
        arr[index++] = neg.front();
        neg.pop();
    }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends