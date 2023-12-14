// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxSum = 0;
        int n = nums.size();

        for(int i = 0;i<k;i++){
            sum += nums[i];
        }
        maxSum = sum;
        
        for(int i = k;i < n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            maxSum = max(maxSum , sum);
        }

        return maxSum/k;

    }
};
