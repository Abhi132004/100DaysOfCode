// https://leetcode.com/problems/h-index/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin() , citations.end());;

        int n = citations.size();
        int index = 0;//cnt

        while(index < n && n-index > citations[index]){
            index++;
        }

        return n - index;
        

    }
};
