// https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int reach = 0;

        for(int idx = 0;idx<nums.size();idx++){
            
            if(reach < idx){
                return false;
            }
            reach = max(reach , idx + nums[idx]);


        }
        
        return true;

    }
};
