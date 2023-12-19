// https://leetcode.com/problems/candy/

#include <vector>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }

        std::vector<int> candies(ratings.size(), 1);

        // Traverse from left to right
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Traverse from right to left
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total number of candies needed.
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
