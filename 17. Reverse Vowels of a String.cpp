// https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string reverseVowels(string s) {
        
        char* arr = s.data();
        int i = 0 , j = s.length()-1;

        string vowels = "aeiouAEIOU";

        while(i<j){
            while(i<j){
                char ch = arr[i];
                if(vowels.find_first_of(ch)!=-1){
                    break;
                }
                i++;
            }

            while(i<j){

                char ch1 = arr[j];
                if(vowels.find_first_of(ch1)!=string::npos){
                    break;
                }
                j = j-1;
            }
            if(i<j){
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
                

            }
        }
        
        return arr;

    }
};
