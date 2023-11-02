// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1089846965/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>check;
        sort(potions.begin() , potions.end());

        for(long long i : spells){
            int s = 0; int r = potions.size() - 1;
            int count = 0;
            while(s<=r){
                int mid = s + (r-s)/2;
                if(i*potions[mid] >= success){
                    count += r-mid+1;
                    r = mid-1;
                }
                else{
                    s = mid + 1;
                }
            }
            check.push_back(count);
        }

        return check;


    }
};
