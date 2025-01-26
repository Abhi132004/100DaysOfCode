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

class Solution {
  public:
      bool isPrime(int k){
        if(k == 3) return 1;
        
        if(k%2 == 0 || k%3 == 0) return 0;
        
        for(int i=5;i*i<=k;i+=6){
            if(k%i == 0 || k%(i+2)==0) return 0;
        }
        return 1;
    }
  public:
    vector<int> getPrimes(int n) {
        vector<int>vec;
        if(n>=2) vec.push_back(2);
        
        for(int i=3;i<=n;i++){
            if(isPrime(i)) vec.push_back(i);
        }

        int i=0, j = vec.size()-1;
        while(i<=j){
            if(vec[i]+vec[j] == n) return {vec[i], vec[j]};
            if(vec[i]+vec[j] < n) i++;
            else j--;
        }
        
        return {-1, -1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    
cout << "~" << "\n";
}
}

// } Driver Code Ends