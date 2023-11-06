// https://leetcode.com/submissions/detail/1090559459/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int index = 0;  // Initialize the index for the target array
        
        for (int i = 1; i <= n && index < target.size(); i++) {
            // Push the current number from the stream to the stack
            ans.push_back("Push");
            
            // If the number from the stream matches the target, move to the next target element
            if (i == target[index]) {
                index++;
            } else {
                // If not, pop the number from the stack
                ans.push_back("Pop");
            }
        }
        
        return ans;
    }
};
