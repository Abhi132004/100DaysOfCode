//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool prime( int N )
{
    
  if( N == 2 ) return true ;
    
    for( int i = 2 ; i*i <= N ; i++ )
    {
        if( N % i == 0 )return false ;
    }
    
    return true; 
    
}
    

public: 
    long long int largestPrimeFactor(int N)
    {
   
 
        vector< int > ans ;  
        if( prime( N ) ) return N ;  
        
        int largestprime = INT_MIN ;

      for( int i =  2  ; i <=  sqrt( N ) ; i++ )
      {
          if( N % i == 0 )
          {
              if( prime(i)  )
              {
                  largestprime = max( largestprime , i );
              } 
               
              if( prime( N/i ) )
              {
                  largestprime = max( largestprime , N/i );
              }
          }
           
      }
       
      return largestprime ;

  }      
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends