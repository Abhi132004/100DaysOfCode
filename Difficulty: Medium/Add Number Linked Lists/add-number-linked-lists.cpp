//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
     Node *reverse(Node *head){
      Node *curr=head,*prev=NULL,*nextNode=NULL;
      while(curr!=NULL){
          nextNode=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextNode;
      }
      return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        if(!num1) return num2;
        if(!num2) return num1;
        Node *list1=reverse(num1);
        Node *list2=reverse(num2);
        Node *dummy=new Node(-1);
        Node *returnHead=dummy;
        int carry=0;
        while(list1!=NULL || list2!=NULL || carry){
            int sum=carry+(list1!=NULL ? list1->data : 0)+(list2!=NULL ? list2->data : 0);
            carry=sum/10;
            int rem=sum%10;
            Node *newNode=new Node(rem);
            dummy->next=newNode;
            dummy=dummy->next;
            if(list1!=NULL)  list1=list1->next;
            if(list2!=NULL)  list2=list2->next;
        }
        Node *ans=reverse(returnHead->next);
        while(ans->data==0) ans=ans->next;  //041+12
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends