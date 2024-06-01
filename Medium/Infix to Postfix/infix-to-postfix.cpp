//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string s) {
    string str = "";
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            str.push_back(s[i]);
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                str.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // pop '('
            }
        } else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                str.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all the operators from the stack
    while (!st.empty()) {
        str.push_back(st.top());
        st.pop();
    }

    return str;
}
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends