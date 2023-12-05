// https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1){
            return;
        }

        int left = 0 ; int right = 0;
        int temp = 0;

        while(right < n){
            if(nums[right] == 0){
                right++;
            }
            else{
                swap(nums[right] , nums[left]);
                left++;
                right++;
            }

        }
            
   

    }
};
