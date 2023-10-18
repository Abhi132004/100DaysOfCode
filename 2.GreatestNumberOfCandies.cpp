// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;
        for(int i = 0;i<candies.size();i++){
            if(candies[i] + extraCandies  >= *max_element(candies.begin() , candies.end())){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }

        return v;
    }
};
