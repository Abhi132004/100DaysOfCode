//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        
        
        int i = 0 , j = 0 , sum = 0 , mx = 0 , start = 0 , end = -1 , n = arr.size();
        
        while(j<n){
            
            if(arr[j] >= 0){
                sum+=arr[j];
                j++;
            }
            else{
                if(sum > mx){
                    mx = sum;
                    start = i;
                    end = j-1;
                }
                sum = 0;
                j++;
                i = j;
            }
            
        }
        
        if(sum > mx){
            start = i;
            end = j-1;
        }
        
        if(end == -1){
            return {-1};
        }
        
        vector<int> ans;
        for(int i = start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from the input string

        Solution obj;
        vector<int> result = obj.findSubarray(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no non-negative subarray is found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << "\n~\n"; // Ensure a new line after each test case output
    }

    return 0;
}

// } Driver Code Ends