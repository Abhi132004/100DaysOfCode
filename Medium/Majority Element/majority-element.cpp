//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
    //   int count = 1;
    //     int candidate = a[0];
    //     int maxi = a[0];
    //     for(int i = 1;i<size;i++){
    //         candidate = a[i];
    //         if(maxi == candidate){
    //             count++;
    //         }
    //         else{
    //             count--;
    //         }
    //         if(count == 0){
    //             count++;
    //             maxi = candidate;
    //         }
    //     }
        
    //     if(count > size/2 - 1){
    //         return maxi;
    //     }
    //     else{
    //         return -1;
    //     }
    
    int candidate = 0;
    int count = 0;
    for(int i = 0;i<size;i++){
        if(count == 0)
            candidate = a[i];
        
        if(candidate == a[i]){
            count++;
        }
        else{
            count--;
        }
    }
    
    int ci = 0;
    for(int i = 0;i<size;i++){
        if(a[i] == candidate){
            ci++;
        }
    }
    
    if(ci>size/2){
        return candidate;
    }
    else{
        return -1;
    }
    
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends