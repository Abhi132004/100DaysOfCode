//https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0 , n = gain.size();int sum = 0;
        for(int i = 0;i<n;i++){
            sum +=gain[i];
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};
