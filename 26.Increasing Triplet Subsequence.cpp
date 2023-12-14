// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }

        int left = INT_MAX;
        int j = INT_MAX;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] > j){
                return true;
            }
            else if(nums[i] > left && nums[i] < j){
                j = nums[i];
            }
            else if(nums[i] < left){
                left = nums[i];
            }
        }
        return false;

    }
};
