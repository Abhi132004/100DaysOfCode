// https://leetcode.com/submissions/detail/1110162256/

#include <vector>
using namespace std;
class Solution {
public:
    void helper(int start, int n, int sum, vector<vector<int>>& ans, vector<int>& ansPair, int k) {
        if (sum == n && k == 0) {
            ans.push_back(ansPair);
            return;
        }

        for (int i = start; i <= 9; i++) {
            ansPair.push_back(i);
            helper(i + 1, n, sum + i, ans, ansPair, k - 1);
            ansPair.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ansPair;
        helper(1, n, 0, ans, ansPair, k);
        return ans;
    }
};
