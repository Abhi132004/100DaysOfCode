//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else if(sum%2==0){
            sum=sum/2;
            int t[n+1][sum+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(i==0){
                       t[i][j]=0; 
                    }
                    if(j==0){
                        t[i][j]=1;
                    }
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(arr[i-1]<=j){
                    t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
         return t[n][sum];
        }
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends