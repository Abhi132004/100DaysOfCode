//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static bool cmp(pair<int,int>&a , pair<int,int>&b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int,int> mp;
        vector<int> vec;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        
        
        vector<pair<int,int>> frequiences (mp.begin(),mp.end());
        sort(frequiences.begin(),frequiences.end(),cmp);
        
        for(int i = 0;i<k && i<frequiences.size();i++){
            vec.push_back(frequiences[i].first);
        }
        return vec;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends