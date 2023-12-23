// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0 , mini = INT_MAX ,j = 0 ;

        int sum = 0;
        int n = nums.size();

        while(i<n){
            sum += nums[i];

            while(sum >= target){
                mini = min(mini, i-j+1);
                sum -=nums[j];
                
                j++;

            }
            i++;

        }

        return mini == INT_MAX ? 0 : mini;
    }
};
