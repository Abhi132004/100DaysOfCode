//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find minimum number of candies.
    int minCandy(vector<int> &arr) {
        int N = arr.size();
        // Creating a vector with size N and initializing all elements to 1.
        vector<int> c(N, 1);

        // Iterating over the arr array starting from index 1.
        for (int i = 1; i < N; i++)
            // If the current rating is greater than the previous rating,
            // increment the current candy count by 1.
            if (arr[i] > arr[i - 1])
                c[i] = c[i - 1] + 1;

        // Iterating over the arr array backwards starting from the second last index.
        for (int i = N - 2; i >= 0; i--)
            // If the current rating is greater than the next rating,
            // update the current candy count to the maximum of its current value and
            // the next candy count plus 1.
            if (arr[i] > arr[i + 1])
                c[i] = max(c[i], c[i + 1] + 1);

        // Initializing a variable res to store the total number of candies.
        int res = 0;

        // Iterating over the candies vector and adding each candy count to res.
        for (auto t : c)
            res += t;

        // Returning the total number of candies.
        return res;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr = inputLine();

        Solution obj;
        cout << obj.minCandy(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends