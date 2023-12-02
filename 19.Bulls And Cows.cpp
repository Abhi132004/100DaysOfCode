// https://leetcode.com/problems/bulls-and-cows/solutions/4140229/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int n = secret.size();
        int cows = 0;

        unordered_map<int , int> mp1;
        unordered_map<int , int> mp2;

        for(int  i = 0;i<n;i++){
            if(secret[i] == guess[i]){
                bulls++;
            }

            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }

        for(int j = 0;j<n;j++){
            if(mp1[secret[j]] > 0 && mp2[secret[j]] > 0){
                cows++;
                mp1[secret[j]]--;
                mp2[secret[j]]--;

            }
        }

        if(cows >= bulls){
            cows = cows-bulls;
        }

        string a = to_string(cows);
        string b = to_string(bulls);

        return b + "A" + a + "B";



        


    }
};
