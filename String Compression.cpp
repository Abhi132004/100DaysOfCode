https://leetcode.com/problems/string-compression/submissions/1134947811/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    int compress(std::vector<char>& chars) {
        int n = chars.size();

        int writeIndex = 0;
        int readIndex = 0;

        while (readIndex < n) {
            char currentChar = chars[readIndex];
            int count = 0;

            // Count consecutive repeating characters
            while (readIndex < n && chars[readIndex] == currentChar) {
                readIndex++;
                count++;
            }

            chars[writeIndex++] = currentChar;

            // Append count only if it's greater than 1
            if (count > 1) {
                std::string count_str = std::to_string(count);
                for (char c : count_str) {
                    chars[writeIndex++] = c;
                }
            }
        }

        return writeIndex;
    }
};
