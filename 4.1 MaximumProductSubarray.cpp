// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

    int n = nums.size();
    if(n==0){
        return 0;
    }

    int maxProductCheck = nums[0] ; int minProductCheck = nums[0];
    int maxProduct = nums[0];

    for(int i = 1;i<nums.size();i++){

        if(nums[i] < 0){
            swap(maxProductCheck , minProductCheck);
        }

        maxProductCheck = max(nums[i] , maxProductCheck*nums[i]);
        minProductCheck = min(nums[i] , minProductCheck*nums[i]);
        maxProduct = max(maxProduct , maxProductCheck);
    }
    return maxProduct;


    }
};
