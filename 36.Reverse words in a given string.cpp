// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
    string reverseWords(string S) 
    { 
        // code here 
        
        vector<string> w;
        string temp = "";
        stringstream ss(S);
        while(getline(ss , temp , '.')){
            w.push_back(temp);
        }
        
        temp = "";
        for(int i = w.size()-1;i>=0;i--){
          temp.append(w[i]);
          temp.push_back('.');
        }
        
        temp.pop_back();
        return temp;
        
        
        
    } 
