// https://leetcode.com/submissions/detail/1095948076/
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        unordered_map<char, int> charIndexMap;

        for (int i = 0; i < s.size(); i++) {
            if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >=start) {
                start = charIndexMap[s[i]] + 1;
            }

            charIndexMap[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
