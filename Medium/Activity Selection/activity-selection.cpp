//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
     int activitySelection(vector<int> start, vector<int> End, int n)
    {
        // Your code here
        
        vector<pair<int,int>> pr;
        
        
        for(int i = 0;i<n;i++){
            pr.push_back({End[i] , start[i]});
        }
        
        sort(pr.begin(),pr.end());
        int lastEndTime = pr[0].first;
        
       
        
        int count = 1;
        for(int i = 1;i<n;i++){
            if(pr[i].second > lastEndTime){
                count++;
                lastEndTime = pr[i].first;
            }
        }
        
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends