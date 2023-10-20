// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp ="";
        stringstream ss(s);

        while(ss>>temp){
            words.push_back(temp);
        }
        temp = "";

        for(int i = words.size()-1;i>=0;i--){
            temp.append(words[i]);
            temp.push_back(' ');
        }

        temp.pop_back();
        return temp;

    }   
};
