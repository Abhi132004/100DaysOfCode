//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* reverseBetween(int m, int n, Node* head) {
        if (m == n)
            return head;

        Node *revs = NULL, *revs_prev = NULL;
        Node *revend = NULL, *revend_next = NULL;

        int i = 1;
        Node* curr = head;
        while (curr && i <= n) {
            if (i < m)
                revs_prev = curr;

            if (i == m)
                revs = curr;

            if (i == n) {
                revend = curr;
                revend_next = curr->next;
            }

            curr = curr->next;
            i++;
        }
        revend->next = NULL;

        revend = reverse(revs);

        if (revs_prev)
            revs_prev->next = revend;
        else
            head = revend;

        revs->next = revend_next;
        return head;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int a = arr[0], b = arr[1];

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* newhead = ob.reverseBetween(a, b, head);
        printList(newhead);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends