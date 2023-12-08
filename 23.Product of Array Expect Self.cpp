// https://leetcode.com/problems/product-of-array-except-self/description/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        if(n<1){
            return output;
        }
        if(n==1){
            return nums;
        }

        int left = 1;
        for(int i = 0;i<n;i++){
            left = left * nums[i];
            output.push_back(left);
        }

        int product = 1;
        for(int i = n-1;i>0;i--){
            output[i] = output[i-1] * product;
            product = product * nums[i];
        } 
        output[0] = product;

        return output;

    }
};
